cmake_minimum_required(VERSION 3.8)
project(Ass1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CMakeLists.txt
        dbLib.cpp
        dbLib.h
        eventLib.cpp
        eventLib.h
        listLib.h
        main.cpp
        processData.cpp)

add_executable(Ass1 ${SOURCE_FILES})