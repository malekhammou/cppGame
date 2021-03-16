cmake_minimum_required(VERSION 3.17)
project(player)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(player
        player.cpp
        player.h main.cpp)
