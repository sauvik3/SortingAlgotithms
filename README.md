# SortingAlgotithms
[![Build status](https://ci.appveyor.com/api/projects/status/u2nde5h43oexwgv4/branch/master?svg=true)](https://ci.appveyor.com/project/sauvik3/SortingAlgotithms/branch/master)
[![Coverage Status](https://coveralls.io/repos/github/sauvik3/SortingAlgotithms/badge.svg?branch=master)](https://coveralls.io/github/sauvik3/SortingAlgotithms?branch=master)

C-Style implementation of basic Sorting Algorithms:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Merge Sort
* Quick Sort

This project was started to study following:

* CMake build system
* GoogleTest Framework
* GoogleBench Framework
* Generate Code Coverage

The project can build as cross-platform, and has option for building as static or shared library.

To Do:

* Write proper benchmark tests:
    - Possibly estimate swap iterations
* Look at the ABI for the library
* Convert library to accept template interface
* Update tests to run on template basis
