cmake_minimum_required(VERSION 3.1)

project(igraph-cpp  VERSION 0.0.1
                    DESCRIPTION "igraph-cpp is a C++ wrapper for igraph"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -pedantic)
add_compile_options(-O3 -march=native -shared -std=c++14 -fPIC)

include_directories(include)
add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" OFF)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()
