# Kruskal’s Algorithm – Programming Assignment 6

## Student Information
- **Full Name:** Asiyah Speight  
- **Student ID:** 2357167  
- **Chapman Email:** aspeight@chapman.edu  
- **Course:** CPSC-350 (Data Structures and Algorithms)  
- **Section:** 02  
- **Assignment:** PA6 – Kruskal’s Algorithm: Minimum Spanning Tree

---

## Submitted Source Files
- `main.cpp`  
- `WGraph.cpp`  
- `WGraph.h`  
- `graph.txt` *(sample input used for testing)*

---

## Description
This program reads a weighted, undirected graph from an input file and computes its **Minimum Spanning Tree (MST)** using **Kruskal’s algorithm**.

- The input file contains an adjacency matrix and ends with the keyword `END`.
- The MST is constructed using a **Union-Find (Disjoint Set)** structure to avoid cycles.
- The program prints:
  - The total cost of the MST.
  - An **adjacency matrix** for the MST where non-MST edges are displayed as `0`.

---

## Notes on Implementation
- The MST logic is implemented in the `computeMST()` method of the `WGraph` class.
- A list of edges is created and sorted by weight.
- A Union-Find structure is used to detect and prevent cycles.
- STL containers (`vector`, `algorithm`) are used for clarity and performance.
- Matrix formatting has been verified to match the example output.

---

## Known Issues or Limitations
- No known compile-time or runtime errors.
- Assumes input graph is **connected**; otherwise, output may be incomplete.

---

## References
- [C++ STL Documentation – cppreference.com](https://en.cppreference.com) — used for `vector`, `sort`, and syntax clarification.
- Peer discussion with Chantelle Chan on formatting expectations (no code shared).
- **ChatGPT** used to debug logic and verify conformance to MST output specification from the assignment PDF.

---

## How to Compile and Run

```bash
# Compile using g++
g++ -std=c++11 -o kruskal main.cpp WGraph.cpp

# Run using your input file (e.g. graph.txt)
./kruskal graph.txt