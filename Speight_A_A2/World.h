/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * World.h - Manages multiple levels in the game world.
 */

#ifndef WORLD_H
#define WORLD_H
 
#include "Level.h"
 
class World {
    public:
         World(int levels, int gridSize, int lives); // Constructor to initialize the game world with levels and settings
         ~World(); // Destructor to free allocated memory
 
         // Getters for the world properties
         int getNumLevels() const; // Get the number of levels
         int getGridSize() const; // Get the grid size for each level
         int getInitialLives() const; // Get Mario's initial lives
 
         // Returns a pointer to a level
         Level* getLevel(int index);
 
    private:
         int numLevels; // Total number of levels in the game
         int gridSize; // Grid size for each level (NxN)
         int initialLives; // Starting lives for Mario
         Level** levels; // Dynamically allocated array of levels 
};
 
#endif 