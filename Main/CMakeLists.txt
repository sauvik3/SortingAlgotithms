project(Main LANGUAGES CXX)
cmake_minimum_required (VERSION 3.1)

# Use C++11
set(CMAKE_CXX_STANDARD 14)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

# list of source files
set(SOURCE_FILES
	src/Main.cpp
	include/Sorting.h
	include/BubbleSort.h
	include/InsertionSort.h
	include/MergeSort.h
	include/QuickSort.h
	include/SelectionSort.h
	include/Utils.h
)

add_executable(Main ${SOURCE_FILES})

if(NOT MSVC)
    target_compile_options(Main PUBLIC -Wall -pedantic)
endif(NOT MSVC)

if(USE_SHARED)
	add_definitions(-DUSE_SHARED)
	add_definitions(-DDLL_IMPORTS)
	target_link_libraries(Main Sorting_shared)
else(USE_SHARED)
    target_link_libraries(Main Sorting_static)
endif(USE_SHARED)
