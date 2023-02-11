cmake_minimum_required(VERSION 3.5)

project(qogin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/qogin/mainwindow.cpp
        src/qogin/mainwindow.h
        src/qogin/mainwindow.ui
        src/qogin/accesswindow.h
        src/qogin/accesswindow.cpp
        src/qogin/accesswindow.ui
        src/qogin/postgresql.h
        src/qogin/postgresql.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq -lstdc++")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qogin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qogin APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qogin SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qogin
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qogin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${PQXX_LIB} ${PQ_LIB})

set_target_properties(qogin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS qogin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qogin)
endif()

