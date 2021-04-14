cmake_minimum_required(VERSION 3.15)

project(made_in_cpp)

add_compile_options(/std:c++latest)

include_directories(lib)

add_subdirectory(src)

add_subdirectory(example)
add_subdirectory(test)
