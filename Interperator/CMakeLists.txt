cmake_minimum_required(VERSION 3.20)
project(factory_method)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(factory_method AddExpression.cpp AddExpression.h C23_1.cpp Expression.cpp Expression.h ValExpression.cpp ValExpression.h)
