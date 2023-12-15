cmake_minimum_required(VERSION 3.27)
project(ToDoApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDoApp main.cpp
        Task.cpp
        Task.h
        Tasks.cpp
        Tasks.h
        ConsoleMenu.cpp
        ConsoleMenu.h
        FileManager.cpp
        FileManager.h)
