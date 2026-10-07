## PROJECT WRITTEN IN POLISH
# Origami Layers Simulation

This project implements an algorithmic solution in C for analyzing and simulating paper folding (origami) and determining the number of paper layers at specific points after a series of geometric operations and pinprick queries.

## About the Project

The program processes a sequence of origami construction steps and queries to evaluate how many layers of paper are pierced when a pin is inserted at a given coordinate $(x, y)$ on a specific sheet $k$. 

Supported geometric shapes and operations include:
* **Rectangles (`P`)**: Closed rectangles with sides parallel to the coordinate axes.
* **Circles (`K`)**: Closed circles defined by a center point and radius.
* **Folds (`Z`)**: Sheets created by folding an existing sheet along a straight line defined by two points. Points on the right side of the crease map to the left, duplicating layers and requiring recursive tracking of overlapping coordinates.

## Technical Details

* **Geometric Precision**: Utilizes a small epsilon threshold (`epsilon = 0.000001`) for floating-point comparisons (`long double`) to handle precision issues safely.
* **Vector & Line Operations**: Computes point reflections (crease symmetry), vector cross products for side-of-a-line checks, and boundary containment for rectangles and circles.
* **Dynamic Memory**: Efficiently manages memory allocation for sheet structures and query lists using standard C library functions (`malloc`, `free`).

## Compilation and Execution

The project compiles using `gcc` with standard optimization flags and math library linking (`-lm`):

    gcc @opcje origami.c -o origami.e -lm

Running the program (input data provided via standard input):

    ./origami.e < input.in

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
