cmake_minimum_required(VERSION 3.10)
project(Matrixcalc)

set(CMAKE_CXX_STANDARD 11)

add_executable(Matrixcalc main.cpp Source/Matrix.cpp Source/Matrix.h source/Vector.cpp source/Vector.h)