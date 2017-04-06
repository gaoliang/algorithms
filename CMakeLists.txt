cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories("include")

add_executable(quick_sort src/quick_sort.cpp include/SortableList.h)

add_executable(merge_sort src/merge_sort.cpp include/SortableList.h)