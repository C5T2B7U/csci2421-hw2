cmake_minimum_required(VERSION 3.3)
project(6936HW2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp bag1.cpp)
add_executable(6936HW2 ${SOURCE_FILES})