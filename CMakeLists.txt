cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
project(mathkit CXX)


set(SOURCES
    src/main.cpp    
    src/lib.cpp
)

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
