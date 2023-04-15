cmake_minimum_required(VERSION 3.25)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

add_library(data_structures
        vector/vector.c
        vector/voidVector.c
        )
