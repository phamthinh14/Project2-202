cmake_minimum_required(VERSION 3.15)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2 main.cpp Foundable.h Game.h Wizard.h Foundable.cpp Wizard.cpp Game.cpp)