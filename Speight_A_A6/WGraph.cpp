/*
 * Full Name: Asiyah Speight
 * Student ID: 2357167
 * Chapman Email: aspeight@chapman.edu
 * Course Number and Section: CPSC 350-02
 * Assignment: PA6 – Kruskal's Algorithm
 *
 * This WGraph class is based on code written by Dr. Linstead in the Graphs 4 lecture.
 * It represents a weighted, undirected graph using an adjacency matrix, and includes
 * a method to compute a Minimum Spanning Tree (MST) using Kruskal's Algorithm.
 */

#include "WGraph.h"
#include <iostream>
#include <vector>
#include <algorithm>  // Fixed typo: should be <algorithm>, not <algorithms>
#include <limits>

/*
Edge structure:
Seen in the "PA6 help" PDF file, edges are represented as (node1, node2, weight)
[Ref: Slide showing p-queue]
*/
struct Edge {
    VertexID src;
    VertexID dest;
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;  // 🔧 Fixed syntax: removed stray semicolon & fixed comparison
    }
};

/*
Union Find Helper Functions:
Used to detect cycles and merge components correctly.
[Ref: Final slides in "PA6 help"]
*/
int find(std::vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);  // Path compression
    return parent[i];  // 🔧 Fixed: missing semicolon
}

void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// constructors
WGraph::WGraph() {
    m_size = 0;
    m_adj = nullptr;
}

WGraph::WGraph(unsigned int sz) {
    m_size = sz;
    m_adj = new double*[m_size];
    for (unsigned int i = 0; i < m_size; ++i) {
        m_adj[i] = new double[m_size];
        for (unsigned int j = 0; j < m_size; ++j)
            m_adj[i][j] = std::numeric_limits<double>::max();  // No edge
    }
}

WGraph::~WGraph() {
    for (unsigned int i = 0; i < m_size; ++i)
        delete[] m_adj[i];
    delete[] m_adj;
}

// edge operations
void WGraph::addEdge(VertexID i, VertexID j, double w) {
    if (i < m_size && j < m_size) {
        m_adj[i][j] = w;
        m_adj[j][i] = w;  // Undirected graph
    }
}

void WGraph::removeEdge(VertexID i, VertexID j) {
    if (i < m_size && j < m_size) {
        m_adj[i][j] = std::numeric_limits<double>::max();
        m_adj[j][i] = std::numeric_limits<double>::max();
    }
}

bool WGraph::areAdjacent(VertexID i, VertexID j) {
    return m_adj[i][j] < std::numeric_limits<double>::max();
}

/*
Kruskal's Algorithm
[Ref: Final slides of PA 6 Help — correct fix uses union-find]
*/
void WGraph::computeMST() {
    std::vector<Edge> edges;

    // 1) Add all edges from the upper triangle of the adjacency matrix
    // [Ref: “Create a min priority queue with all the edges”]
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = i + 1; j < m_size; ++j) {  // 🔧 fixed loop: should be j = i + 1 to avoid duplicates
            if (m_adj[i][j] < std::numeric_limits<double>::max()) {
                edges.push_back({i, j, m_adj[i][j]});
            }
        }
    }

    std::sort(edges.begin(), edges.end());  // Sort ascending by weight

    // 2) Initialize union-find
    std::vector<int> parent(m_size);
    std::vector<int> rank(m_size, 0);
    for (unsigned int i = 0; i < m_size; ++i)
        parent[i] = i;

    // 3) Prepare MST adjacency matrix
    std::vector<std::vector<double>> mst(m_size, std::vector<double>(m_size, 0.0));
    double totalCost = 0.0;

    // 4) Kruskal's main loop
    for (const Edge& e : edges) {  // fixed: was `for (const Edge : edges)` — missing variable name
        int root1 = find(parent, e.src);
        int root2 = find(parent, e.dest);

        if (root1 != root2) {
            unionSets(parent, rank, root1, root2);
            mst[e.src][e.dest] = e.weight;
            mst[e.dest][e.src] = e.weight;
            totalCost += e.weight;
        }
    }

    // 5) Print result
    std::cout << "The MST Cost is: " << totalCost << std::endl;
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = 0; j < m_size; ++j) {
            std::cout << static_cast<int>(mst[i][j]);  // To match formatting from example
            if (j != m_size - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}