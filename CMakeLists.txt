cmake_minimum_required(VERSION 3.17)
project(BondPricer)

set(CMAKE_CXX_STANDARD 20)

add_executable(BondPricer src/main.cpp src/Bond.cpp src/Bond.h)
