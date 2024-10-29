cmake_minimum_required(VERSION 3.10)

# Укажите имя вашего проекта
project(WarshipGame)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите директорию для заголовочных файлов
include_directories(include)

# Укажите исходные файлы
file(GLOB SOURCES "src/*.cpp")

# Создайте исполняемый файл
add_executable(war ${SOURCES} "include/Input.h" "src/Input.cpp" "include/Player.h" "include/Round.h" "src/Round.cpp" "src/Player.cpp")
