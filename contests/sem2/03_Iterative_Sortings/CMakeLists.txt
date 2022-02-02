cmake_minimum_required(VERSION 3.20)
project(03_Iterative_Sortings)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(A_bubble_Sort A_bubble_sort.cpp)
add_executable(B_selection_sort B_selection_sort.cpp)
add_executable(C_insertion_sort C_insertion_sort.cpp)
add_executable(D_insertion_sort_with_bubble_sort D_insertion_sort_with_bubble_sort.cpp)
add_executable(E_taxi E_taxi.cpp)
