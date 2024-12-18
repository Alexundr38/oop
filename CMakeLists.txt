cmake_minimum_required(VERSION 3.10)

project(WarshipGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include Game/include Abilitys/include InputManager/include OutputManager/include Exception/include)
include_directories("c:/MinGW/json-develop/include/nlohmann")

file(GLOB SOURCES "src/*.cpp" "OutputManager/*.cpp" "InputManager/*.cpp" "Exception/*.cpp" "Abilitys/*.cpp" "Game/*.cpp")

add_executable(war ${SOURCES} "OutputManager/include/OutputManager.h"   "Game/include/PlayerUseAbilityState.h" "Game/PlayerUseAbilityState.cpp" "Game/include/GameController.h" )

#cmake_minimum_required(VERSION 3.10)
#project(my_project)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(Abilitys)
#add_subdirectory(Exception)
#add_subdirectory(InputManager)
#add_subdirectory(OutputManager)
#add_subdirectory(Game)
#add_subdirectory(src)
#include_directories("c:/MinGW/json-develop/include/nlohmann")

#install(TARGETS my_executable DESTINATION bin)
