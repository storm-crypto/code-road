cmake_minimum_required(VERSION 3.17)
project(Hash)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hash main.cpp HashTable.h UnorderedSet.h UnorderedMap.h BitSet.h BloomFilter.h)