cmake_minimum_required(VERSION 3.25)
project(18 C)

set(CMAKE_C_STANDARD 11)

add_executable(18 main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/vector/vectorVoid.c libs/data_structures/vector/vectorVoid.h)
