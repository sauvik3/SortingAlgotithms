project(Sorting LANGUAGES CXX)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/include)

# list of source files
set(SOURCE_FILES
	src/BubbleSort.cpp
	src/InsertionSort.cpp
	src/MergeSort.cpp
	src/QuickSort.cpp
	src/SelectionSort.cpp
	src/Utils.cpp
	include/Sorting.h
	include/BubbleSort.h
	include/InsertionSort.h
	include/MergeSort.h
	include/QuickSort.h
	include/SelectionSort.h
	include/Utils.h
)

if(USE_SHARED)
	add_definitions(-DUSE_SHARED)
	add_definitions(-DDLL_EXPORTS)
	add_library(Sorting_shared SHARED ${SOURCE_FILES})
	set_target_properties(Sorting_shared PROPERTIES POSITION_INDEPENDENT_CODE 1)
	target_link_libraries(Sorting_shared PUBLIC coverage_config)
else()
	add_library(Sorting_static STATIC ${SOURCE_FILES})
	target_link_libraries(Sorting_static PUBLIC coverage_config)
endif()
