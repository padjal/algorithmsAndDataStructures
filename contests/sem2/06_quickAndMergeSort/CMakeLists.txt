cmake_minimum_required(VERSION 3.20)
project(06_quickAndMergeSort)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(A A.cpp)
add_executable(B B.cpp)
add_executable(C C.cpp)
add_executable(D D.cpp)
add_executable(E E.cpp)
add_executable(F F/F.cpp F/student-ski.h F/read-writer.h F/participant_solution.cpp)
add_executable(badSort badSort.cpp)
