cmake_minimum_required(VERSION 3.10)
project(g4json)


add_executable(g4json main.cpp)
target_include_directories(g4json PUBLIC inc)