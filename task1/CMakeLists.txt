cmake_minimum_required(VERSION 3.1)

project(task1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1 main.cpp signal.cpp noise.cpp wavsaver.cpp operations.cpp signal.h common.h noise.h wavsaver.h operations.h)
