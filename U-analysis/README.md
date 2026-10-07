## PROJECT WRITTEN IN POLISH
# U-Strict Maximum Intervals Analysis

This project implements an efficient, linear-time ($O(n)$) C++ solution for analyzing and finding optimal U-strict intervals for a sequence of coordinate points $(x_i, y_i)$ with strictly increasing $x$ coordinates.

## About the Project

Given a threshold $U$ and a set of points where $x_1 < x_2 < \dots < x_n$, an interval $[l, r]$ is considered U-strict if the absolute difference between any two $y$-values within the interval is at most $U$. A U-strict interval is maximal if it is not strictly contained within any other U-strict interval.

The quality of a U-strict interval $[l, r]$ is defined as:
$$\text{Quality} = \frac{x_r - x_l}{\sqrt{r - l + 1}}$$

For every index $i$ from $1$ to $n$, the program identifies the maximal U-strict interval containing $i$ that achieves the highest quality, resolving ties by preferring the interval with the smaller left endpoint.

## Key Technical Features

* **Monotonic Deques**: Utilizes dual monotonic deques (tracking running maximums and minimums of $y$-values) to generate maximal intervals in a sliding-window approach.
* **High-Precision Arithmetic**: Uses `__int128_t` for cross-multiplication comparisons of interval qualities, completely avoiding precision loss from square root floating-point operations.
* **Optimal Complexity**: Processes all elements and queries efficiently in $O(n)$ time complexity.

## Compilation and Execution

The project compiles using `g++` under the `C++23` standard with the provided configuration options and math library linking:

    g++ @opcjeCpp u_analysis.cpp -lm -o u_analysis.e

Running the program (input data provided via standard input):

    ./u_analysis.e < input.in

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM)  
University of Warsaw
