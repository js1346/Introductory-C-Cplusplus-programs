## PROJECT WRITTEN IN POLISH
# Bags & Items Management (Worki)

This project implements an efficient C++ data structure and library for tracking the hierarchical configuration of bags, items, and a desk ("biurko"). The implementation handles complex containment relationships, recursive item counts, and a global inversion operation (`na_odwrot`) in constant time.

## About the Project

The simulation tracks items and bags placed either directly on a desk or nested inside other bags. Each bag receives a unique sequential number starting from 0, while items and uncontained desk space are managed dynamically. 

Key functionalities include:
* **Nesting (`wloz`)**: Placing items or bags into other bags located on the desk.
* **Unpacking (`wyjmij`)**: Removing items or bags from their current container back onto the desk.
* **Inversion (`na_odwrot`)**: A specialized operation that swaps the contents of a specific desk-level bag with everything outside of it on the desk simultaneously, executed in $O(1)$ time.
* **Memory Management (`gotowe`)**: Clean destruction and deallocation of all tracked nodes and structures to prevent memory leaks under Valgrind checks.

## Technical Details

* **Constant Time Complexity**: Designed to execute core operations in strict $O(1)$ time complexity to meet strict performance criteria.
* **Standard C++ Standard**: Compiled under the modern `C++23` standard using `g++`.

## Compilation and Execution

The project compiles using `g++` along with optimization options and the C++23 standard:

    g++ @opcjeCpp main.cpp bags.cpp -o main.e

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
