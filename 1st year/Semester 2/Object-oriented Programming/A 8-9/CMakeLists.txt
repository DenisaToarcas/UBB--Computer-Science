cmake_minimum_required(VERSION 3.24)
project(a89-Denisa_Toarcas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt_tools/6.5.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(.)

add_executable(a89-Denisa_Toarcas
        main.cpp
        Duration/Duration.cpp
        Duration/Duration.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        Repository/TestsRepo.cpp
        Repository/TestsRepo.h
        Tutorial/Tutorial.cpp
        Tutorial/Tutorial.h
        Repository/userRepo.cpp
        Repository/userRepo.h
        Service/Validator.h
        Service/Validator.cpp
        Service/ServiceExceptions.h
        Service/ServiceExceptions.cpp
        Repository/CSVhandler.h
        Repository/CSVhandler.cpp
        Repository/RepositoryExceptions.h
        Repository/RepositoryExceptions.cpp
        Repository/UserExceptions.h
        Repository/UserExceptions.cpp
        Repository/HTMLhandler.h
        Repository/HTMLhandler.cpp
        GUI.h
        GUI.cpp
        AdministratorModeGUI.h
        AdministratorModeGUI.cpp
        UserModeGUI.cpp
        UserModeGUI.h
        ui_AdministratorWindow.h)

target_link_libraries(a89-Denisa_Toarcas
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

