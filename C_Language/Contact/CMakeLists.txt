cmake_minimum_required(VERSION 3.17)
project(Contact C)

set(CMAKE_C_STANDARD 99)

add_executable(Contact main.c contact.c contact.h)