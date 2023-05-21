cmake_minimum_required(VERSION 3.20)
project(factory_method)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(factory_method  Dir.cpp Dir.h File.cpp File.h main.cpp Node.cpp Node.h)
