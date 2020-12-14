project(Main LANGUAGES CXX)
cmake_minimum_required(VERSION 2.8)

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
	target_link_libraries(Main PRIVATE Sorting_shared)
else()
    target_link_libraries(Main PRIVATE Sorting_static)
endif()
