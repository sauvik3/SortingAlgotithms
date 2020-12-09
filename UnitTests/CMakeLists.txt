project(UnitTests LANGUAGES CXX)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/include)

# list of source files
set(SOURCE_FILES
	src/UnitTests.cpp
	include/UnitTests.h
	include/Sorting.h
	include/BubbleSort.h
	include/InsertionSort.h
	include/MergeSort.h
	include/QuickSort.h
	include/SelectionSort.h
	include/Utils.h
)

add_executable(UnitTests ${SOURCE_FILES})

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest/googletest-download"
)
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest/googletest-download"
)
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()


# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_CURRENT_BINARY_DIR}/googletest/googletest-src"
				 "${CMAKE_CURRENT_BINARY_DIR}/googletest/googletest-build"
)

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
include_directories("${gtest_SOURCE_DIR}/include"
					"${gmock_SOURCE_DIR}/include"
)

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
if(USE_SHARED)
	add_definitions(-DUSE_SHARED)
	add_definitions(-DDLL_IMPORTS)
	target_link_libraries(UnitTests Sorting_shared gtest gtest_main)
else()
    target_link_libraries(UnitTests Sorting_static gtest gtest_main)
endif()

# Make the test runnable with
# $ make test
enable_testing()
add_test(NAME    UnitTests
         COMMAND UnitTests)
