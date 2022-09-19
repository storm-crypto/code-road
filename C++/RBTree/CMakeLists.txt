cmake_minimum_required(VERSION 3.17)
project(RBTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(RBTree main.cpp RBTree.h map.h set.h Iterator.h)