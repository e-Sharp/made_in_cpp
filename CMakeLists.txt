cmake_minimum_required(VERSION 3.15)

project(symbolus)

if(MSVC)
    add_compile_options(/std:c++latest /W4)
else()
    add_compile_options(-std=c++20 -Wall)
endif()

include_directories(lib)

add_subdirectory(src)

add_subdirectory(example)
add_subdirectory(test)
