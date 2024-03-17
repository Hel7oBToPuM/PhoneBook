#include <iostream>
#include <fstream>
#include <unordered_map>
#include <mutex>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <phone_book.grpc.pb.h>

// Реализация сервиса
class PhoneBookServiceImpl final : public PhoneBookService::Service {
private:
    std::string phone_book_filename; // Имя файла, в котором хранится состояние между перезапусками

    // Структура описывающая все поля контакта, кроме номера телефона
    struct ContactInformation{
        std::string first_name;
        std::string last_name;
        std::string patronymic;
        std::string note;
    };
    // Хэш-таблица с одинаковыми ключами для хранения контактов
    std::unordered_multimap<std::string, ContactInformation> contacts;
    std::mutex contacts_mutex; // Мьютекс для синхронизации доступа к контейнеру с контактами


public:
    // Конструктор сервиса
    explicit PhoneBookServiceImpl(const std::string& filename) : phone_book_filename(filename) {
        PhoneBook binary_phone_book;
        // Считывание из файла предыдущего состояния сервера
        std::fstream input(phone_book_filename, std::ios::in | std::ios::binary);
        if (!input) {
            // Создание файла, если его не существует
            input = std::fstream(phone_book_filename, std::ios::out);
            std::cout << phone_book_filename << ": File not found. Creating a new file." << std::endl;
        }
        else if (!binary_phone_book.ParseFromIstream(&input))
            // Вывод ошибки при неудачном считывании предыдущего состояния сервера
            std::cerr << "Failed to parse phone book file: " << phone_book_filename
                      << ". Phone book data maybe corrupted!" << std::endl;
        input.close();

        // Заполнение контейнера для контактов данными из файла
        for(const auto& con : binary_phone_book.contacts())
            contacts.insert({con.phone(), {con.first_name(), con.last_name(),
                                           con.patronymic(), con.note()}});
    }
    ~PhoneBookServiceImpl() override {
        PhoneBook binary_phone_book;

        // Сериализация контейнера с контактами в сгенерированный protobuf класс
        for (const auto& [phone, info] : contacts) {
            auto contact = binary_phone_book.add_contacts();
            contact->set_phone(phone);
            contact->set_first_name(info.first_name);
            contact->set_last_name(info.last_name);
            contact->set_patronymic(info.patronymic);
            contact->set_note(info.note);
        }

        // Сохранение состояния сервера в файл
        std::fstream output(phone_book_filename, std::ios::out | std::ios::trunc | std::ios::binary);
        if (!binary_phone_book.SerializeToOstream(&output))
            std::cerr << "Failed to save phone book to file: " << phone_book_filename
            << ". Phone book data maybe corrupted!" << std::endl;
    }

    // Добавление контакта
    grpc::Status addContact (grpc::ServerContext* context, const Contact* request, google::protobuf::Empty* response) override {
        std::unique_lock<std::mutex> ul(contacts_mutex);

        // Поиск совпадение по номеру телефона
        auto found_conts = contacts.equal_range(request->phone());
        if (found_conts.first != found_conts.second) {
            // Поиск совпадений в ФИО
            for (auto it = found_conts.first; it != found_conts.second; ++it) {
                auto found_full_name = it->second.first_name + it->second.last_name + it->second.patronymic;

                auto adding_full_name = request->first_name() + request->last_name() + request->patronymic();

                // Отправка ошибки клиенту, если контакт уже существует
                if (found_full_name == adding_full_name)
                    return {grpc::ALREADY_EXISTS, "Contact already exist!"};
            }
        }

        // Добавление контакта
        contacts.insert({request->phone(),{request->first_name(), request->last_name(),
                                           request->patronymic(), request->note()}});
        ul.unlock();
        return grpc::Status::OK;
    };

    // Удаление контакта
    grpc::Status deleteContact (grpc::ServerContext* context, const DeleteRequest* request, google::protobuf::Empty* response) override {
        const auto& contact = request->contact();
        std::unique_lock<std::mutex> ul(contacts_mutex);

        // Поиск совпадение по номеру телефона
        auto found_conts = contacts.equal_range(contact.phone());
        if (found_conts.first != found_conts.second) {
            // Поиск совпадений в ФИО
            for (auto it = found_conts.first; it != found_conts.second; ++it) {
                auto found_full_name = it->second.first_name + it->second.last_name + it->second.patronymic;
                auto adding_full_name = contact.first_name() + contact.last_name() + contact.patronymic();

                // Удаление в случае наличия такого контакта
                if (found_full_name == adding_full_name) {
                    contacts.erase(it);
                    return grpc::Status::OK;
                }
            }
        }

        ul.unlock();
        // Отправка ошибки в случае отсутствия контакта
        return {grpc::NOT_FOUND, "Contact does not exist!"};
    };

    // Поиск контактов по паттерну
    grpc::Status searchContact(grpc::ServerContext* context, const SearchRequest* request
                               , grpc::ServerWriter<Contact>* writer) override {
        const auto& req = request->contact();
        std::unique_lock<std::mutex> ul(contacts_mutex);

        /* Перебор контактов и поиск совпадений в существующих контактах (в томе числе и по заметке).
        Для всех полей кроме заметок проверяется начало вхождения с нулевого элемента.
        Для заметки проверяется вхождение подстроки в любой позиции заметки*/
        for (const auto& [phone, info] : contacts) {
            if ((req.phone().empty() || phone.find(req.phone()) == 0) &&
                (req.first_name().empty() || info.first_name.find(req.first_name()) == 0) &&
                (req.last_name().empty() || info.last_name.find(req.last_name()) == 0) &&
                (req.patronymic().empty() || info.patronymic.find(req.patronymic()) == 0) &&
                (req.note().empty() || info.note.find(req.note()) != std::string::npos)) {

                // Создание protobuf-объекта подходящего контакта для отправки
                Contact response_contact;
                response_contact.set_phone(phone);
                response_contact.set_first_name(info.first_name);
                response_contact.set_last_name(info.last_name);
                response_contact.set_patronymic(info.patronymic);
                response_contact.set_note(info.note);

                // Отправка в Stream контакта
                if(!writer->Write(response_contact))
                    return {grpc::UNKNOWN, "Failed to send response!"};
            }

        }
        ul.unlock();
        return grpc::Status::OK;
    }
};

// Функция запускаемая в отдельном потоке для обработки выключения сервера
void serverShutDown(std::unique_ptr<grpc::Server>& runningServer) {
    if (runningServer != nullptr) {
        std::string input;
        while(input != "stop")
            std::getline(std::cin, input);
        std::cout << "Server is shutting down!" << std::endl;
        runningServer->Shutdown();
    }
}

// Функция для переопределения файла, в который сохраняется состояние сервера, по аргументу командной строки
std::string getDBFilename(int argc, char** argv) {
    std::string db_filename("phonebook.data");
    std::string arg_str("--db_file");
    if (argc > 1) {
        std::string argv_1 = argv[1];
        size_t pos = argv_1.find(arg_str);
        if (pos != std::string::npos) {
            pos += arg_str.size();
            if (argv_1[pos] == '=')
                db_filename = argv_1.substr(pos + 1);
        }
    }
    return db_filename;
}

int main(int argc, char** argv) {
    std::string server_address("0.0.0.0:50051");
    std::string phone_book_filename(getDBFilename(argc, argv));

    PhoneBookServiceImpl service(phone_book_filename);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << server_address << std::endl;
    std::cout << "Enter \"stop\" to shutdown the server" << std::endl;
    std::thread shutdown_thread([&server] { serverShutDown(server); });;
    shutdown_thread.detach();

    server->Wait();
    return 0;
}