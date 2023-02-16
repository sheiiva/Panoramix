### CMakeLists.txt: Panoramix CMake file
###
### 2023, February 15
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

cmake_minimum_required(VERSION 3.5)

# Project information
project(
    Panoramix
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/sheiiva/Panoramix"
    LANGUAGES CXX
)

# Place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Change this to false if you want to disable warnings_as_errors in developer mode
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT FALSE)

# Set libraries versions
include(${CMAKE_SOURCE_DIR}/config/versions.cmake)

### BUILD ###

set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/sources)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(CONFIG_DIR ${CMAKE_SOURCE_DIR}/config)

set(SOURCES
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/arguments/ArgumentChecker.cpp
    ${SOURCES_DIR}/thread/ThreadPool.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${INCLUDE_DIR}/arguments
        ${INCLUDE_DIR}/arguments/Usage
        ${INCLUDE_DIR}/thread
    )

target_link_libraries(
    ${PROJECT_NAME}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CMAKE_CXX_STANDARD 20
        CMAKE_CXX_STANDARD_REQUIRED ON
)

### BUILD TESTS ###
add_subdirectory(tests)