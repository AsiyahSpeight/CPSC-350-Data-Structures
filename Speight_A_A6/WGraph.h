/*
 * Full Name: Asiyah Speight
 * Student ID: 2357167
 * Chapman Email: aspeight@chapman.edu
 * Course Number and Section: CPSC 350-02
 * Assignment: PA6 – Kruskal's Algorithm
 *
 * This WGraph class is based on code written by Dr. Linstead in the Graphs 4 lecture.
 * It uses a fixed-size adjacency matrix and implements Kruskal's algorithm using arrays only.
 */

#ifndef WGRAPH_H
#define WGRAPH_H

#include <cstdlib>

typedef unsigned int VertexID;

class WGraph {
public:
    WGraph();
    WGraph(unsigned int sz);
    ~WGraph();

    void addEdge(VertexID i, VertexID j, double w);
    void removeEdge(VertexID i, VertexID j);
    bool areAdjacent(VertexID i, VertexID j);
    void computeMST(); // the method that we will be using from the assignment

private:
    double** m_adj;
    unsigned int m_size;
};

#endif