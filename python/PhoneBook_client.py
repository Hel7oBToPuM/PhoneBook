import tkinter as tk
from tkinter import ttk
# Импорт пакета grpc
import grpc
from google.protobuf.json_format import MessageToDict
# Импорт сгенерированных классов
import phone_book_pb2
import phone_book_pb2_grpc


class PhoneBookApp(tk.Tk):
    def __init__(self):
        super().__init__()
        # Создание и настройка окна
        self.title("PhoneBook")
        self.geometry("800x600")
        self.resizable(False, False)
        self.protocol("WM_DELETE_WINDOW", self.onClose)

        # Создание класса обертки gRPC
        self.grpc_client = gRPC_Client()

        # Создание виджета с вкладками
        ttk.Style(self).configure('TNotebook.Tab', width=self.winfo_screenwidth())
        self.notebook = ttk.Notebook(self)
        self.notebook.pack(expand=True, fill=tk.BOTH)

        # Создание вкладок
        self.tabs = {name: ttk.Frame(self.notebook) for name in ["add", "search"]}
        self.notebook.add(self.tabs["add"], text='Добавить контакт')
        self.notebook.add(self.tabs["search"], text='Найти(удалить) контакт')

        # Разделение окна поиска на форму для поиска и вывода результатов
        self.search_frames = {name: ttk.Frame(self.tabs["search"]) for name in ["search", "treeview"]}

        # Словарь для инпутов для операций добавления, поиска, удаления
        self.entrys = {name: {} for name in ['add', 'search', 'delete']}

        # Словарь с label вывода ошибок и результатов для каждой операции
        self.error_labels = {name: None for name in ['add', 'search', 'delete']}
        ttk.Style().configure("Error.TLabel", foreground="red",
                              font=("Helvetica", 12, "bold"), anchor="center")

        # Словарь для кнопок для отправки данных и выполнения операций
        self.accept_buttons = {name: None for name in ['add', 'search', 'delete']}

        # Словарь - [название поля]:[название параметра]
        self.params = {'Телефон': 'phone', 'Имя': 'first_name',
                       'Фамилия': 'last_name', 'Отчество': 'patronymic', 'Заметка': 'note'}
        # Настройка вкладок
        self.configureAddTab()
        self.configureSearchTab()

    # Закрытие приложения
    def onClose(self):
        self.grpc_client.close()
        self.destroy()

    # Настройка вкладки добавления контакта
    def configureAddTab(self):
        # Настройка grid
        for column, weight in [(0, 2), (1, 3), (2, 2)]:
            self.tabs["add"].columnconfigure(column, weight=weight)
        for row, weight in [(0, 2), (13, 2)]:
            self.tabs["add"].rowconfigure(row, weight=weight)

        # Создание инпутов для добавления контакта
        add_labels = {}
        for i, text in enumerate(self.params.keys()):
            add_labels[text] = ttk.Label(self.tabs["add"], text=text)
            add_labels[text].grid(row=i * 2 + 1, column=1, pady=(10, 1), sticky='w')

            self.entrys["add"][text] = tk.Entry(self.tabs["add"], validate="key")
            self.entrys["add"][text].grid(row=i * 2 + 2, column=1, sticky='we')

        # Установка валидатора для инпутов
        self.setEntryValidators(self.entrys["add"])

        # Создание label для вывода статуса операции добавления
        self.error_labels["add"] = ttk.Label(self.tabs["add"], style="Error.TLabel")
        self.error_labels["add"].grid(row=11, column=1, pady=(10, 3), padx=0)

        # Создание кнопки для выполнения операции добавления
        self.accept_buttons["add"] = ttk.Button(self.tabs["add"], text="Добавить", width=30, command=self.add_handler)
        self.accept_buttons["add"].grid(row=12, column=1)

    # Настройка вкладки поиска/удаления контакта
    def configureSearchTab(self):
        # Настройка вкладки поиска
        self.tabs["search"].columnconfigure(0, weight=1)
        for row, weight in [(0, 0), (1, 1)]:
            self.tabs["search"].rowconfigure(row, weight=weight)

        # Настройка frame для поиска
        for column, weight in [(0, 1), (4, 1)]:
            self.search_frames["search"].columnconfigure(column, weight=weight)
        self.search_frames["search"].grid(row=0, column=0, sticky="nsew")

        # Создание инпутов для поиска
        labels = {}
        for i, text in enumerate(self.params.keys()):
            labels[text] = ttk.Label(self.search_frames["search"], text=text)
            self.entrys["search"][text] = ttk.Entry(self.search_frames["search"], validate="key")
            if text == 'Телефон':
                labels[text].grid(row=0, column=2, padx=3, pady=(10, 1), sticky='nsw')
                self.entrys["search"][text].grid(row=1, column=2, padx=3, sticky='nsew')
            elif text == 'Заметка':
                labels[text].grid(row=4, column=1, columnspan=3, pady=(10, 1), padx=(80, 80), sticky='nsw')
                self.entrys["search"][text].grid(row=5, column=1, columnspan=3, padx=(80, 80), sticky='nsew')
            else:
                labels[text].grid(row=2, column=i, padx=3, pady=(10, 1), sticky='nsw')
                self.entrys["search"][text].grid(row=3, column=i, padx=3, sticky='nsew')

        # Установка валидатора для инпутов
        self.setEntryValidators(self.entrys["search"])

        # Создание label для вывода статуса операции поиска
        self.error_labels["search"] = ttk.Label(self.search_frames["search"], style="Error.TLabel")
        self.error_labels["search"].grid(column=1, row=6, columnspan=3, pady=(10, 0))

        # Создание кнопки для выполнения операции поиска
        self.accept_buttons["search"] = ttk.Button(self.search_frames["search"],
                                                   text="Найти", command=self.search_handler)
        self.accept_buttons["search"].grid(column=2, row=7, sticky="ew", pady=(5, 15))

        # Настройка frame для вывода результатов поиска
        self.search_frames["treeview"].columnconfigure(0, weight=1)
        self.search_frames["treeview"].rowconfigure(0, weight=1)
        self.search_frames["treeview"].grid(row=1, column=0, sticky="nsew")

        # Создание treeview для вывода результатов
        self.entrys["delete"]["treeview"] = ttk.Treeview(self.search_frames["treeview"],
                                                         columns=list(self.params.keys()), show='headings')
        for column in self.params.keys():
            self.entrys["delete"]["treeview"].heading(column, text=column)
            self.entrys["delete"]["treeview"].column(column, minwidth=110, width=(110 if column != "Заметка" else 340))
        self.entrys["delete"]["treeview"].grid(column=0, row=0, sticky="nsew")

        # Создание scrollbar для прокрутки результатов
        scrollbar_y = ttk.Scrollbar(self.search_frames["treeview"], orient="vertical",
                                    command=self.entrys["delete"]["treeview"].yview)
        scrollbar_y.grid(row=0, column=1, sticky="ns")
        self.entrys["delete"]["treeview"].configure(yscrollcommand=scrollbar_y.set)

        # Создание label для вывода статуса операции удаления
        self.error_labels["delete"] = ttk.Label(self.search_frames["treeview"], style="Error.TLabel")
        self.error_labels["delete"].grid(row=2, pady=(5, 0))

        # Создание кнопки для выполнения операции удаления
        self.accept_buttons["delete"] = ttk.Button(self.search_frames["treeview"], text="Удалить",
                                                   command=self.delete_handler, state="disabled")
        self.accept_buttons["delete"].grid(row=3, sticky="nsew", padx=300, pady=(5, 15))
        self.entrys["delete"]["treeview"].bind('<<TreeviewSelect>>',
                                               lambda e: self.accept_buttons["delete"].config(
                                                   state=("normal" if self.entrys["delete"]["treeview"].selection()
                                                          else "disabled")))

    # Валидатор для инпутов
    def setEntryValidators(self, entrys):
        for i, text in enumerate(self.params.keys()):
            if text == 'Телефон':
                entrys[text].insert(0, '+')
                entrys[text].configure(validatecommand=(self.register(
                    lambda value: value.startswith('+') and (value[1:].isdigit() or value[1:] == "")), "%P"))
            elif text in ['Имя', 'Фамилия', 'Отчество']:
                entrys[text].configure(validatecommand=(self.register(
                    lambda value: all(char.isalpha() or char.isspace() for char in value)), "%P"))

    # Обработчик кнопки добавления
    def add_handler(self):
        try:
            # Попытка добавить контакт
            self.grpc_client.addContact({self.params[name]: entry.get().strip() for name, entry in self.entrys["add"].items()})
            self.error_labels["add"].configure(text="Контакт успешно добавлен", foreground="green")

            # Очистка полей
            for name, entry in self.entrys["add"].items():
                entry.delete(0 if name != 'Телефон' else 1, "end")

        except grpc.RpcError as error:
            # Обработка неудачной попытки
            if error.code() == grpc.StatusCode.ALREADY_EXISTS:
                self.error_labels["add"].configure(text="Контакт уже существует", foreground="red")
            else:
                self.error_labels["add"].configure(text="Сервис недоступен", foreground="red")

        # Очистка сообщения о статусе операции
        self.error_labels["add"].after(3000, lambda: self.error_labels["add"].configure(text=""))

    # Обработчик кнопки поиска
    def search_handler(self):
        # Удаление всех строк в treeview
        self.entrys["delete"]["treeview"].delete(*self.entrys["delete"]["treeview"].get_children())

        try:
            # Попытка поиска контакта
            response = self.grpc_client.searchContact(
                {self.params[name]: entry.get() for name, entry in self.entrys["search"].items()})
            # Проверка результатов поиска
            contact_found = False
            for contact in response:
                contact_found = True
                contact_info = {value: MessageToDict(contact, preserving_proto_field_name=True).get(value, '') for
                                key, value in self.params.items()}
                self.entrys["delete"]["treeview"].insert(parent="", index="end", values=list(contact_info.values()))
            # Если пришел пустой ответ
            if not contact_found:
                self.error_labels["search"].configure(text="Контакт отсутствует")
        except grpc.RpcError:
            # Обработка неудачной попытки
            self.error_labels["search"].configure(text="Сервис недоступен")

        # Очистка сообщения о статусе операции
        self.error_labels["search"].after(3000, lambda: self.error_labels["search"].configure(text=""))

    # Обработчик кнопки удаления
    def delete_handler(self):
        # Получение значения выбранного контакта
        selected_row = self.entrys["delete"]["treeview"].selection()[0]
        keys = self.entrys["delete"]["treeview"]["column"]
        values = [str(val) for val in self.entrys["delete"]["treeview"].item(selected_row)["values"]]
        if values[0] != '+':
            values[0] = '+' + values[0]

        try:
            # Попытка удаления контакта
            self.grpc_client.deleteContact({self.params[name]: value for name, value in zip(keys, values)})

            # Вывод статуса, удаление из списка, блокировка кнопки
            self.error_labels["delete"].configure(text="Контакт удален", foreground="green")
            self.entrys["delete"]["treeview"].delete(selected_row)
            self.accept_buttons["delete"].config(state='disabled')
        except grpc.RpcError as error:
            # Обработка неудачной попытки
            if error.code() == grpc.StatusCode.NOT_FOUND:
                # Вывод статуса, удаление из списка, блокировка кнопки
                self.error_labels["delete"].configure(text="Контакт не существует", foreground="red")
                self.entrys["delete"]["treeview"].delete(selected_row)
                self.accept_buttons["delete"].config(state='disabled')
            else:
                self.error_labels["delete"].configure(text="Сервис недоступен", foreground="red")

        # Очистка сообщения о статусе операции
        self.error_labels["delete"].after(3000, lambda: self.error_labels["delete"].configure(text=""))


# Класс-обертка для stub
class gRPC_Client:
    def __init__(self, host='localhost', port=50051):
        self.channel = grpc.insecure_channel(f"{host}:{port}")
        self.stub = phone_book_pb2_grpc.PhoneBookServiceStub(self.channel)

    def addContact(self, contact_info):
        contact = phone_book_pb2.Contact(**contact_info)
        return self.stub.addContact(contact)

    def searchContact(self, contact_info):
        search_contact = phone_book_pb2.Contact(**contact_info)
        search_request = phone_book_pb2.DeleteRequest(contact=search_contact)
        return self.stub.searchContact(search_request)

    def deleteContact(self, contact_info):
        delete_contact = phone_book_pb2.Contact(**contact_info)
        delete_request = phone_book_pb2.DeleteRequest(contact=delete_contact)
        return self.stub.deleteContact(delete_request)

    def close(self):
        self.channel.close()


if __name__ == '__main__':
    app = PhoneBookApp()
    app.mainloop()
