## PROJECT WRITTEN IN POLISH
# Highway Motels Analysis

This project implements an efficient, linear-time solution to a classic algorithmic problem involving finding optimal triplets of motels along a highway.

## Problem Description & Requirements

The goal of the program is to process a sequence of $n$ motels (each described by its network number and distance from the start of the highway) and find two specific triplets of motels $A, B, C$ belonging to **three different networks**
1. **The Closest Triplet**: one that minimizes the maximum of the distances ($\vert{}B-A\vert{}$ and $\vert{}C-B$).
2. **The Farthest Triplet**: one that maximizes the minimum of the distances ($\vert{}B-A\vert{}$ and $\vert{}C-B$).

## Key Architectural and Performance Features

* **$O(n)$ Time Complexity**: The algorithm processes data in linear time, allowing for seamless handling of large data sets containing up to one million elements.
* **Index Precomputation (Helper Arrays)**: Utilizes predecessor and successor arrays (`prev1`, `prev2`, `next1`, `next2`) to rapidly locate appropriate motels from alternative networks without expensive nested loop searches.
* **Memory Optimization**: Dynamic memory management for network arrays and auxiliary pointers with controlled resource cleanup (`zwolnij_pamiec`).

## Compilation and Execution

The project compiles using `gcc` along with a dedicated optimization options file:

    gcc @opcje triple_hotels.c -o triple_hotels.e

Running the program (input data provided via standard input):

    ./triple_hotels.e < dane.in

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
