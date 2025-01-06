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
        src/Server/clientprocessor.cpp
        include/Server/clientprocessor.h
        src/Network/winsocket.cpp
        include/Network/winsocket.h
        src/Network/ipaddr.cpp
        include/Network/ipaddr.h
        )

target_include_directories(${PROJECT_NAME} PRIVATE include)
