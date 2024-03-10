cmake_minimum_required(VERSION 3.24)
project(a45_DenisaToarcas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.idea)

add_executable(a45_DenisaToarcas
        Duration.cpp
        Duration.h Tutorial.h Tutorial.cpp Repository.h Repository.cpp Service.h Service.cpp UI.h UI.cpp start_of_program.cpp userRepo.h userRepo.cpp TestsRepo.h TestsRepo.cpp TestTutorial.cpp TestTutorial.h TestUSER.cpp TestUSER.h TestService.cpp TestService.h)
