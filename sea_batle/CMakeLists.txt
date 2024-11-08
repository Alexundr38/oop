cmake_minimum_required(VERSION 3.10)

# Укажите имя вашего проекта
project(WarshipGame)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите директорию для заголовочных файлов
include_directories(include)
include_directories("c:/MinGW/json-develop/include/nlohmann")

# Укажите исходные файлы
file(GLOB SOURCES "src/*.cpp")
# Создайте исполняемый файл
add_executable(war ${SOURCES} "include/OutputManager.h" "src/OutputManager.cpp")

