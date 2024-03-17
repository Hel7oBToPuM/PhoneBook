cmake_minimum_required(VERSION 3.20)
project(PhoneBook)
set(CMAKE_CXX_STANDARD 20)

# Поиск библиотеки protobuf и gRPC
find_package(protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)
# Поиск бинарника protoc и python-плагина для генерации python-кода для клиента
find_program(PROTOC_BINARY protoc)
find_program(GRPC_PYTHON_PLUGIN grpc_python_plugin)

# Создание переменных с путями для выполнения сборки
set(PROTO_IMPORT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
set(PROTO_CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
set(PROTO_PYTHON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/python")
set(PB_PROTO_SRCS "${PROTO_CPP_DIR}/phone_book.pb.cc")
set(PB_PROTO_HDRS "${PROTO_CPP_DIR}/phone_book.pb.h")
set(PB_GRPC_SRCS "${PROTO_CPP_DIR}/phone_book.grpc.pb.cc")
set(PB_GRPC_HDRS "${PROTO_CPP_DIR}/phone_book.grpc.pb.h")

# Добавление цели для генерации C++ файлов из .proto
add_library(proto-objects OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/proto/phone_book.proto")
target_include_directories(proto-objects PUBLIC "$<BUILD_INTERFACE:${PROTO_CPP_DIR}>")
target_link_libraries(proto-objects PUBLIC protobuf::libprotobuf)
# Генерация C++ файлов
protobuf_generate(
        TARGET proto-objects
        IMPORT_DIRS ${PROTO_IMPORT_DIR}
        PROTOC_OUT_DIR ${PROTO_CPP_DIR})
protobuf_generate(
        TARGET proto-objects
        LANGUAGE grpc
        GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
        PLUGIN "protoc-gen-grpc=\$<TARGET_FILE:gRPC::grpc_cpp_plugin>"
        IMPORT_DIRS ${PROTO_IMPORT_DIR}
        PROTOC_OUT_DIR ${PROTO_CPP_DIR})

# Добавление всех сгенерированных файлов в виде библиотеки
add_library(pb_grpc_proto ${PB_PROTO_SRCS} ${PB_PROTO_HDRS} ${PB_GRPC_SRCS} ${PB_GRPC_HDRS})
target_link_libraries(pb_grpc_proto PUBLIC gRPC::grpc++ protobuf::libprotobuf)

# Создание итоговой цели сборки
add_executable(PhoneBook_server src/PhoneBook_server.cpp)
target_include_directories(PhoneBook_server PUBLIC ${PROTO_CPP_DIR})
target_link_libraries(PhoneBook_server pb_grpc_proto)

# Вызов protoc для генерации файлов для python-клиента
add_custom_command(
        OUTPUT "${PROTO_PYTHON_DIR}/phone_book_pb2.py"
               "${PROTO_PYTHON_DIR}/phone_book_pb2.pyi"
               "${PROTO_PYTHON_DIR}/phone_book_pb2_grpc.py"
        COMMAND ${PROTOC_BINARY}
        ARGS -I ${PROTO_IMPORT_DIR} --python_out=${PROTO_PYTHON_DIR}
        --pyi_out=${PROTO_PYTHON_DIR} --grpc_out=${PROTO_PYTHON_DIR}
        --plugin=protoc-gen-grpc=${GRPC_PYTHON_PLUGIN}
        "${PROTO_IMPORT_DIR}/phone_book.proto"
        DEPENDS "${PROTO_IMPORT_DIR}/phone_book.proto"
)