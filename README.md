# University Introductory Course Programming Portfolio (C / C++)

This repository contains a curated collection of advanced algorithms, data structures, and low-level systems programming projects developed during introductory course opening Computer Science and Mathematics (JSIM) studies at the **University of Warsaw (MIM UW)**. 

Each project is fully self-contained within its respective directory, complete with its own source code, build automation, and dedicated documentation.

## Repository Structure & Projects

* **[triple_hotels/]** — **Highway Motels Analysis (C)**  
  An optimal, linear-time ($O(n)$) algorithm solving a complex geometric/sequence problem to find closest and farthest triplets of motels across different networks.
  
* **[origami/]** — **Origami Layers Simulation (C)**  
  A geometric simulation engine evaluating paper folding operations (rectangles, circles, and crease reflections) and tracking paper layer counts via pinprick coordinate queries.

* **[bags/]** — **Bags & Items Management (C++)**  
  An efficient hierarchical data structure tracking nests of bags and items on a desk, supporting constant-time ($O(1)$) containment operations and a global inversion feature (`na_odwrot`).

* **[u-analysis/]** — **U-Strict Maximum Intervals Analysis (C++)**  
  An optimized $O(n)$ algorithm utilizing monotonic deques and high-precision cross-multiplication (`__int128_t`) to evaluate and extract optimal U-strict maximum intervals based on mathematical quality metrics.

* **[glasses/]** — **Water Glasses Simulation (C++)**  
  A state-space search engine using Breadth-First Search (BFS), custom state hashing, and GCD pruning to determine the minimum number of operations required to transition water glasses to a target volume.

## Technologies & Standards
* **Languages:** C (gnu23 standard), C++ (C++23 standard)
* **Tools & Utilities:** GCC, Make, Valgrind (memory leak detection and diagnostics)

## Author
**Jakub Skalany**  
Computer Science and Mathematics (JSIM) Student  
University of Warsaw
