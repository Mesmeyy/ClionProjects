cmake_minimum_required(VERSION 3.6)
project(WebBench)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Request_Zzy.h Request_Zzy.cpp Thead_Zzy.h Thead_Zzy.cpp)
add_executable(WebBench ${SOURCE_FILES})