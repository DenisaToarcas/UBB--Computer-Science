cmake_minimum_required(VERSION 3.24)
project(a7_DenisaToarcas_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a7_DenisaToarcas_1
        Duration/Duration.cpp
        Duration/Duration.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        start_of_program.cpp
        Repository/TestsRepo.cpp
        Repository/TestsRepo.h
        Tutorial/Tutorial.cpp
        Tutorial/Tutorial.h
        UI/UI.cpp
        UI/UI.h
        Repository/userRepo.cpp
        Repository/userRepo.h Service/Validator.h Service/Validator.cpp Service/ServiceExceptions.h Service/ServiceExceptions.cpp Repository/CSVhandler.h Repository/CSVhandler.cpp Repository/RepositoryExceptions.h Repository/RepositoryExceptions.cpp Repository/UserExceptions.h Repository/UserExceptions.cpp Repository/HTMLhandler.h Repository/HTMLhandler.cpp)
