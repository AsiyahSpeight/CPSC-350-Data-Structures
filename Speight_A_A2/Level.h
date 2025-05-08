/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Level.h - Defines the structure of a single level in the game.
 * Each level is an NxN grid containing enemies, power-ups, and a boss.
 */

 #ifndef LEVEL_H
#define LEVEL_H

#include "Mario.h"

class Level {
    public:
        Level(int gridSize); // Constructor to initialize level with dynamic grid size
        ~Level(); // Destructor to free dynamically allocated memory

        void generateLevel(); // Generates the level with enemies, power-ups, and a boss
        char getElementAt(int row, int col) const; // Returns the element at a given position in the level grid
        void setElementAt(int row, int col, char element); // Sets the element at a given position in the level grid
        void printLevel() const; // Prints the level grid to the console
        char getRandomDirection() const; // Returns a random direction for an enemy to move
    
    private:
        int size; // Size of the level grid (NxN)
        char** grid; // Dynamically allocated grid for the level
};

#endif