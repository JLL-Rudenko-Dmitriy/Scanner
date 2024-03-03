cmake_minimum_required(VERSION 3.25)
project(Scanner)

set(SCAN_SOURCE Scanner.cpp)

add_library(scn STATIC ${SCAN_SOURCE})