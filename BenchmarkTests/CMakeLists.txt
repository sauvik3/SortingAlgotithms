project(BenchmarkTests LANGUAGES CXX)
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
	src/BenchmarkTests.cpp
	include/Sorting.h
	include/BubbleSort.h
	include/InsertionSort.h
	include/MergeSort.h
	include/QuickSort.h
	include/SelectionSort.h
	include/Utils.h
)

add_executable(BenchmarkTests ${SOURCE_FILES})

if(NOT MSVC)
    target_compile_options(BenchmarkTests PUBLIC -Wall -pedantic)
endif(NOT MSVC)

# Download and unpack googlebench at configure time
configure_file(CMakeLists.txt.in googlebench/googlebench-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googlebench/googlebench-download"
)
if(result)
	message(FATAL_ERROR "CMake step for googlebench failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googlebench/googlebench-download"
)
if(result)
	message(FATAL_ERROR "Build step for googlebench failed: ${result}")
endif()


set(BENCHMARK_ENABLE_TESTING OFF)

# Add googlebench directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_CURRENT_BINARY_DIR}/googlebench/googlebench-src"
				 "${CMAKE_CURRENT_BINARY_DIR}/googlebench/googlebench-build"
)

# add_subdirectory("${googlebenchmark_SOURCE_DIR}" "${googlebenchmark_BINARY_DIR}")
include_directories("${benchmark_SOURCE_DIR}/include")

# Now simply link your own targets against gbenchmark
# etc. as appropriate
if(USE_SHARED)
	add_definitions(-DUSE_SHARED)
	add_definitions(-DDLL_IMPORTS)
	target_link_libraries(BenchmarkTests Sorting_shared benchmark benchmark_main)
else(USE_SHARED)
    target_link_libraries(BenchmarkTests Sorting_static benchmark benchmark_main)
endif(USE_SHARED)

# Make the test runnable with
# $ make test
enable_testing()
add_test(NAME    BenchmarkTests
         COMMAND BenchmarkTests)
