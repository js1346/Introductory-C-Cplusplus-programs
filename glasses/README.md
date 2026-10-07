## PROJECT WRITTEN IN POLISH
# Water Glasses Simulation

This project implements an efficient state-space search algorithm in C++ to solve the water glasses puzzle, determining the minimum number of operations required to reach a specific target volume of water across multiple glasses of varying capacities.

## About the Project

Given $n$ glasses with capacities $x_1, x_2, \dots, x_n$ and target water amounts $y_1, y_2, \dots, y_n$ (starting from all empty), the program calculates the shortest sequence of actions needed to achieve the target configuration. 

Supported operations on glasses include:
* **Fill**: Filling a selected glass to the brim from the tap.
* **Empty**: Pouring all water out of a glass into the sink.
* **Pour**: Transferring water from one glass to another until the source is empty or the destination is full.

If reaching the target state is impossible, the program outputs `-1`.

## Key Technical Features

* **Breadth-First Search (BFS)**: Explores the state space level by level to guarantee the minimum number of operations.
* **State Hashing & Optimization**: Utilizes custom hash functions and unordered sets to track visited states efficiently and prune redundant paths.
* **Greatest Common Divisor (GCD) Pruning**: Implements initial checks using GCD to filter out unreachable configurations prior to full graph traversal.
* **Strict Compiler Compliance**: Designed to compile cleanly under strict warning flags and sanitizers specified for C++23.

## Compilation and Execution

The project compiles using `g++` with the C++23 standard and optimization flags:

    g++ -std=c++23 -pedantic -Wall -Wextra -Werror -O1 glasses.cpp -o glasses.e

Running the program (input data provided via standard input):

    ./glasses.e < input.in

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
