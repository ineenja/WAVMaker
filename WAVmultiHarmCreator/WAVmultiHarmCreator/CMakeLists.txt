cmake_minimum_required(VERSION 3.5)

project(WAVmultiHarmCreator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WAVmultiHarmCreator main.cpp signal.cpp noise.cpp wavsaver.cpp filereader.cpp operations.cpp  signal.h common.h noise.h wavsaver.h operations.h filereader.h)
