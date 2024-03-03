cmake_minimum_required(VERSION 3.25)
project(Parser)

set(PARS_SOURCE parser.cpp)

add_library(pars STATIC ${PARS_SOURCE})