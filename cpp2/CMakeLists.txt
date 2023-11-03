cmake
cmake_minimum_required(VERSION 3.12)
project(my_project)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(my_program main.cpp)
target_link_libraries(my_program PRIVATE ${CONAN_LIBS})