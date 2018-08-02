cmake_minimum_required(VERSION 3.10)
project(Matrixcalc)

set(CMAKE_CXX_STANDARD 11)

add_executable(Matrixcalc main.cpp source/Matrix.h source/Matrix.cpp source/Vector.cpp source/Vector.h)