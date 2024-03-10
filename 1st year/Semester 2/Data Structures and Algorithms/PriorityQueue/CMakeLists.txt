cmake_minimum_required(VERSION 3.24)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 14)

include_directories(PriorityQueue)

add_executable(PriorityQueue
        PriorityQueue/App.cpp
        PriorityQueue/ExtendedTest.cpp
        PriorityQueue/ExtendedTest.h
        PriorityQueue/PriorityQueue.cpp
        PriorityQueue/PriorityQueue.h
        PriorityQueue/ShortTest.cpp
        PriorityQueue/ShortTest.h)
