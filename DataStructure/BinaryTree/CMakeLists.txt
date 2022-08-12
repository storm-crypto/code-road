cmake_minimum_required(VERSION 3.17)
project(BinaryTree C)

set(CMAKE_C_STANDARD 99)
set(Headers Queue.h)

add_executable(BinaryTree  main.c Queue.c)