cmake_minimum_required(VERSION 3.24)
project(A2 C)

set(CMAKE_C_STANDARD 11)

include_directories(a23-DenisaToarcas)

add_executable(A2
        a23-DenisaToarcas/domain.c
        a23-DenisaToarcas/domain.h
        a23-DenisaToarcas/main.c
        a23-DenisaToarcas/repository.c
        a23-DenisaToarcas/repository.h
        a23-DenisaToarcas/service.c
        a23-DenisaToarcas/service.h
        a23-DenisaToarcas/ui.c
        a23-DenisaToarcas/ui.h
        a23-DenisaToarcas/Tests.h
        a23-DenisaToarcas/Tests.c a23-DenisaToarcas/UndoRedo_Repo.h a23-DenisaToarcas/UndoRedo_Repo.c)
