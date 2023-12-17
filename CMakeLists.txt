cmake_minimum_required(VERSION 3.27)
project(ToDoApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDoApp main.cpp
        src/task.cpp
        include/task.h
        src/tasks.cpp
        include/tasks.h
        src/consoleMenu.cpp
        include/consoleMenu.h
        src/fileManager.cpp
        include/fileManager.h
        src/utils.cpp
        include/utils.h)
