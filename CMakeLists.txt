cmake_minimum_required(VERSION 3.26)

project(SimpleCppScanner)

set(SOURCE src/main.cpp)

add_executable(Scanner ${SOURCE})

set_target_properties(Scanner PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)