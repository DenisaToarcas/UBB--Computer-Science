cmake_minimum_required(VERSION 3.24)
project(t2_DenisaToarcas_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_DenisaToarcas_1
        Domain.cpp
        Domain.h Service.cpp Service.h UI.cpp UI.cpp start.cpp)
