cmake_minimum_required(VERSION 3.25)
project(SimpleCppScanner)

set(SOURCE src/main.cpp)


include_directories(lib/scanner)
include_directories(lib/arg_parser)

add_executable(Scanner ${SOURCE})

add_subdirectory(lib/scanner)
add_subdirectory(lib/arg_parser)

target_link_libraries(Scanner pars)
target_link_libraries(Scanner scn)

set_target_properties(Scanner PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)