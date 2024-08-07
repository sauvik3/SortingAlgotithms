project(SortingAlgotithms LANGUAGES CXX)

# Use C++11
set(CMAKE_CXX_STANDARD 14)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

# Code Coverage Configuration
add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Add required flags (GCC & LLVM/Clang)
    target_compile_options(coverage_config INTERFACE
            -O0        # no optimization
            -g         # generate debug info
            --coverage # sets all required flags
    )
    if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else ()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif ()
endif (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

add_subdirectory(Sorting)
add_subdirectory(Main)

option(BUILD_TESTING "Build the testing tree." ON)
# Only build tests if we are the top-level project
# Allows this to be used by super projects with `add_subdirectory`
if (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    add_subdirectory(UnitTests)
    add_subdirectory(BenchmarkTests)
endif (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))

if (USE_SHARED)
    set_target_properties(
            Sorting_shared
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
    )
else (USE_SHARED)
    set_target_properties(
            Sorting_static
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
    )
endif (USE_SHARED)

set_target_properties(
        Main UnitTests BenchmarkTests
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
)

