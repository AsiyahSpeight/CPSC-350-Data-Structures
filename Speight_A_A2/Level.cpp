/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Level.cpp - Implements level generation, interactions, and movement.
 */

 #include "Level.h"
#include <iostream>
#include <cstdlib> // For rand() function

using namespace std;

// Constructor: Initializes the level grid dynamically based on size
Level::Level(int gridSize) : size(gridSize) {
    // Dynamically allocate memory for the grid (2D array)
    grid = new char*[size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
    }
    // Generate the level layout with enemies, coins, and other items
    generateLevel();
}

// Destructor: Frees the dynamically allocated memory for the grid
Level::~Level() {
    for (int i = 0; i < size; ++i) {
        delete[] grid[i]; // Free each row of the grid
    }
    delete[] grid; // Free the grid itself
}

// Generates the level by placing coins, enemies, mushrooms, etc.
void Level::generateLevel() {
    int totalCells = size * size;

    // Randomly place objects based on approximate percentages
    int numCoins = totalCells * 0.30;
    int numGoombas = totalCells * 0.10;
    int numKoopas = totalCells * 0.10;
    int numMushrooms = totalCells * 0.10;

    while (numCoins--) grid[rand() % size][rand() % size] = 'c'; // 'c' for coin
    while (numGoombas--) grid[rand() % size][rand() % size] = 'g'; // 'g' for Goomba
    while (numKoopas--) grid[rand() % size][rand() % size] = 'k'; // 'k' for Koopa
    while (numMushrooms--) grid[rand() % size][rand() % size] = 'm'; // 'm' for mushroom

    grid[rand() % size][rand() % size] = 'b'; // Place the boss ('b')
    grid[rand() % size][rand() % size] = 'w'; // Place the warp pipe ('w')
}

// Returns the element at a given position in the level grid
char Level::getElementAt(int row, int col) const {
    return grid[row][col];
}

// Sets the element at a given position in the level grid
void Level::setElementAt(int row, int col, char element) {
    grid[row][col] = element;
}

// Prints the level grid to the console (for debugging)
void Level::printLevel() const {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

// Returns a random direction for an enemy to move (up, down, left, or right)
char Level::getRandomDirection() const {
    char directions[] = {'U', 'D', 'L', 'R'}; // Directions: U=Up, D=Down, L=Left, R=Right
    return directions[rand() % 4]; // Return a random direction
}