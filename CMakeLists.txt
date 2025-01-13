cmake_minimum_required(VERSION 3.0.0)

# Project name
project(mathkit CXX)

# CPP standard
set(CMAKE_CXX_STANDARD 17)

# Output directory
set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()
set(FullOutputDirectory "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDirectory}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDirectory}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDirectory}")

# Source files
set(SOURCES
    src/main.cpp    
    src/bigint.cpp
)

# Include files
include_directories(include)

# Compile project
add_executable(${PROJECT_NAME} ${SOURCES})

# Link directories to the project
target_include_directories(${PROJECT_NAME} PUBLIC include)

