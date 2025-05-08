# Kruskal’s Algorithm – Programming Assignment 6

## Student Information
- **Full Name:** Asiyah Speight  
- **Student ID:** 2357167  
- **Chapman Email:** aspeight@chapman.edu  
- **Course:** CPSC-350 (Data Structures and Algorithms)  
- **Section:** 02  
- **Assignment:** PA6: Kruskal’s Algorithm – Minimum Spanning Tree

---

## Submitted Source Files
- `main.cpp`  
- `WGraph.cpp`, `WGraph.h`  

---

## Description
This program reads a weighted undirected graph from an input file and computes its **Minimum Spanning Tree (MST)** using **Kruskal’s algorithm**.

- The graph is provided as an **adjacency matrix** in a text file.
- The MST is constructed using a **Union-Find (Disjoint Set)** structure to avoid cycles.
- The total cost of the MST is printed.
- The MST is displayed as an **adjacency matrix** with all non-MST edges set to 0.

---

## Notes on Implementation
- The core logic for Kruskal’s algorithm is implemented in `computeMST()` inside the `WGraph` class.
- A vector of edges is sorted by weight.
- A union-find structure is used to keep track of connected components.
- Once the MST is formed, the program outputs:
  - The total cost of the MST.
  - A matrix showing only the MST edges.
- Standard Template Library (STL) containers such as `vector`, `set`, and `pair` were used to simplify the implementation.

---

## Known Errors / Limitations

- No known compile-time or runtime errors.
- The algorithm currently assumes the input graph is **connected**.
- The output format strictly matches the spec; any deviation will result in a grade penalty, so formatting was verified thoroughly.

---

## References

- [C++ STL Documentation](https://en.cppreference.com) – for `vector`, `set`, and `sort`.
- Peer discussion with Chantelle Chan regarding input matrix formatting (classmate, no code sharing).
- ChatGPT used for debugging union-find logic and validating matrix print format.

---

## How to Compile and Run

```bash
# To compile the program:
g++ *.cpp -o kruskal.exe

# To run the executable:
./kruskal.exe input.txt
