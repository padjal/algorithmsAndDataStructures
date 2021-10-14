cmake_minimum_required(VERSION 3.20)
project(contest6)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        A A.cpp
        B B.cpp
        C C.cpp
        D D.cpp
        E E.cpp)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)
