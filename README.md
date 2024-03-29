# Телефонная книга

**Проект состоит из серверной и клиентской части, реализованных с использованием технологии gRPC.**

# Сервер

### Установка зависимостей

- [Установите gRPC и Protobuf из исходников](https://github.com/grpc/grpc/blob/master/BUILDING.md#build-from-source)

### Сборка

Для сборки сервера (и файлов grpc для python-клиента) выполните следующие команды из корневой папки проекта:
```
cd bin
cmake ..
make
```

### Запуск

**Примечание**
- В папке **bin** хранится файл phonebook.data с тестовыми контактами

Выполните следующие команды из корневой папки проекта:
```
cd bin
./PhoneBook_server
```

##### Запуск с параметрами

Файл с контактами (которые подгружаются при запуске сервера) хранится в папке **bin** и по умолчанию имеет название phonebook.data. Вы можете использовать аргумент командной строки **--db_path** для указания другого файла для контактов.
Пример:
```
./PhoneBook_server --db_path=db.data
```

##### Остановка сервера
Для остановки сервера введите команду **stop**.


# Клиент

### Установка зависимостей

- Установите tkinter:
    - Linux Debian-дистрибутивы
        ```
        sudo apt install python3-tk
        ```
    - macOS
        ```
        brew install python-tk
        ```
- Установите пакеты gRPC и Protobuf:
    - Из корневой папки проекта выполните:
        ```        
        cd python
        pip install -r requirements.txt
        ```

### Запуск

Для запуска выполните следующую команду из корневой папки проекта **(предварительно необходимо выполнить сборку сервера)**:
```
python ./python/PhoneBook_client.py
```
