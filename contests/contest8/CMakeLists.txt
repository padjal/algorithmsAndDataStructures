cmake_minimum_required(VERSION 3.20)
project(contest8)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(A TaskA.cpp)
add_executable(B TaskB.cpp)
add_executable(C TaskC.cpp)
add_executable(D TaskD.cpp)
