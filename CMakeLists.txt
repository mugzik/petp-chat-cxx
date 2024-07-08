cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Chat)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} 
        src/main.cpp
        src/Server/server.cpp
        include/Server/server.h
        src/Network/socket.cpp
        include/Network/socket.h
        )

target_include_directories(${PROJECT_NAME} PRIVATE include)
