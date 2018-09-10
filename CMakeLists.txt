cmake_minimum_required(VERSION 3.11)
project(pong LANGUAGES C)
set(CMAKE_C_STANDARD 11)

set(pong_VERSION_MAJOR 0)
set(pong_VERSION_MINOR 1)
set(pong_VERSION_REVISION 0)

# Configs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Libs
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf >= 2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer >= 2.0.0)

# Build settings
include_directories(${PROJECT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)

add_subdirectory(examples)
