cmake_minimum_required(VERSION 3.24)
project(IteratedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(IteratedList)

add_executable(IteratedList
        IteratedList/App.cpp
        IteratedList/ExtendedTest.cpp
        IteratedList/ExtendedTest.h
        IteratedList/IteratedList.cpp
        IteratedList/IteratedList.h
        IteratedList/ListIterator.cpp
        IteratedList/ListIterator.h
        IteratedList/ShortTest.cpp
        IteratedList/ShortTest.h)
