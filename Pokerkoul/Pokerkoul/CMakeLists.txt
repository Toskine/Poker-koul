cmake_minimum_required(VERSION 3.23)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pokerkoul Pokerkoul/defpoker.h  Pokerkoul/pokerkoul.cpp )
add_executable(Poker "Pokerkoul/Poker.cpp")
