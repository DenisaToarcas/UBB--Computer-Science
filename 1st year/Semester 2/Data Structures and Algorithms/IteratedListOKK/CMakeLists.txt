cmake_minimum_required(VERSION 3.24)
project(IteratedListOKK)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(IteratedListOKK
        src/App.cpp
        src/ExtendedTest.cpp
        src/ExtendedTest.h
        src/IteratedList.cpp
        src/IteratedList.h
        src/ListIterator.cpp
        src/ListIterator.h
        src/ShortTest.cpp
        src/ShortTest.h)
