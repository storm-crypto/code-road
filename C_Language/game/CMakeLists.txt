cmake_minimum_required(VERSION 3.17)
project(game C)

set(CMAKE_C_STANDARD 99)

add_executable(game main.c game.c game.h)