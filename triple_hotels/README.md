## PROJECT WRITTEN IN POLISH
# Highway Motels Analysis

This project implements an efficient, linear-time solution to a classic algorithmic problem involving finding optimal triplets of motels along a highway[cite: 1]. The task was implemented in C and received a grade of **5.0 / 5.0** during academic evaluation by Dr. hab. Jakub Pawlewicz at the University of Warsaw (MIM UW)[cite: 1].

## Problem Description & Requirements

The goal of the program is to process a sequence of $n$ motels (each described by its network number and distance from the start of the highway) and find two specific triplets of motels $A, B, C$ belonging to **three different networks**[cite: 1]:
1. **The Closest Triplet**: one that minimizes the maximum of the distances ($\vert{}B-A\vert{}$ and $\vert{}C-B$)[cite: 1].
2. **The Farthest Triplet**: one that maximizes the minimum of the distances ($\vert{}B-A\vert{}$ and $\vert{}C-B$)[cite: 1].

## Key Architectural and Performance Features

* **$O(n)$ Time Complexity**: The algorithm processes data in linear time, allowing for seamless handling of large data sets containing up to one million elements[cite: 1].
* **Index Precomputation (Helper Arrays)**: Utilizes predecessor and successor arrays (`prev1`, `prev2`, `next1`, `next2`) to rapidly locate appropriate motels from alternative networks without expensive nested loop searches[cite: 1].
* **Memory Optimization**: Dynamic memory management for network arrays and auxiliary pointers with controlled resource cleanup (`zwolnij_pamiec`)[cite: 1].

## Compilation and Execution

The project compiles using `gcc` along with a dedicated optimization options file[cite: 1]:

    gcc @opcje trz.c -o trz.e

Running the program (input data provided via standard input):

    ./trz.e < dane.in

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
