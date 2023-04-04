cmake_minimum_required(VERSION 3.22)
project(HW4_Templates)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW4_Templates hw4.cpp TBuffer.hpp)
add_executable(HW4_Templates_ExtraCredit hw4extra.cpp TBuffer.hpp TOrderedBuffer.hpp)
