cmake_minimum_required(VERSION 3.10)

# Define project
project(MyProject)

# Include src directory
include_directories(${PROJECT_SOURCE_DIR}/src)
message(STATUS PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR})

# Add executable from main.cpp
add_executable(test_project
    src/main.cpp
    src/comp_vectors.cpp
    src/comp_sqrt.cpp)

