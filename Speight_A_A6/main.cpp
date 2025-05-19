/*
 * Full Name: Asiyah Speight
 * Student ID: 2357167
 * Chapman Email: aspeight@chapman.edu
 * Course Number and Section: CPSC 350-02
 * Assignment: PA6 – Kruskal's Algorithm
 */

#include <iostream>
#include <fstream>
#include "WGraph.h"
#include <limits>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./kruskal <filename>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int n;
    file >> n;

    WGraph g(n);

    // Read adjacency matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            double w;
            file >> w;
            if (w != 0.0 && w != std::numeric_limits<double>::max())
                g.addEdge(i, j, w);
        }

    std::string endCheck;
    file >> endCheck;
    if (endCheck != "END") {
        std::cerr << "Missing END keyword in file." << std::endl;
        return 1;
    }

    // Compute and print MST
    g.computeMST();
    return 0;
}