cmake_minimum_required(VERSION 3.17)
project(StackQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(StackQueue main.c Stack.c Stack.h Queue.c Queue.h)