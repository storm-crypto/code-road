cmake_minimum_required(VERSION 3.17)
project(List C)

set(CMAKE_C_STANDARD 99)

add_executable(List main.c SList.c SList.h List.c List.h)