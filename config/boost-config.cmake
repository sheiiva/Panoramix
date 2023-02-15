### boost-config.cmake
###
### 2023, February 15
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

set(BOOST_INCLUDE_LIBRARIES log)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
    Boost
    GIT_REPOSITORY  https://github.com/boostorg/boost.git
    GIT_TAG         ${BOOST_VERSION}
)
FetchContent_MakeAvailable(Boost)

FetchContent_GetProperties(boost)
if (NOT boost_POPULATED)
    FetchContent_Populate(boost)
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR})
endif ()

include_directories(${boost_SOURCE_DIR})