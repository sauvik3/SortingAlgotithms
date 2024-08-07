project(UnitTests LANGUAGES CXX)

# Use C++11
set(CMAKE_CXX_STANDARD 14)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

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

if (USE_SHARED)
    add_definitions(-DUSE_SHARED)
    add_definitions(-DDLL_EXPORTS)
    add_library(Sorting_shared SHARED ${SOURCE_FILES})
    if (NOT MSVC)
        target_compile_options(Sorting_shared PUBLIC -Wall -pedantic)
    endif (NOT MSVC)
    set_target_properties(Sorting_shared PROPERTIES POSITION_INDEPENDENT_CODE 1)
    target_link_libraries(Sorting_shared PUBLIC coverage_config)
else (USE_SHARED)
    add_library(Sorting_static STATIC ${SOURCE_FILES})
    if (NOT MSVC)
        target_compile_options(Sorting_static PUBLIC -Wall -pedantic)
    endif (NOT MSVC)
    target_link_libraries(Sorting_static PUBLIC coverage_config)
endif (USE_SHARED)
