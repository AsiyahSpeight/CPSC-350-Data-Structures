/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * World.cpp - Implements world-level management, including levels and settings.
 */

 #include "World.h"

 using namespace std;
 
 // Constructor: Initializes the world with levels and grid size
 World::World(int levels, int gridSize, int lives) {
     numLevels = levels;
     this->gridSize = gridSize;
     initialLives = lives;
 
     // Allocate memory for levels dynamically
     this->levels = new Level*[numLevels];
     for (int i = 0; i < numLevels; i++) {
         this->levels[i] = new Level(gridSize);
     }
 }
 
 // Destructor: Frees the dynamically allocated memory for levels
 World::~World() {
     for (int i = 0; i < numLevels; i++) {
         delete levels[i]; // Free each level object
     }
     delete[] levels; // Free the array of levels
 }
 
 // Getter: Returns the number of levels in the world
 int World::getNumLevels() const {
     return numLevels;
 }
 
 // Getter: Returns the grid size for each level
 int World::getGridSize() const {
     return gridSize;
 }
 
 // Getter: Returns Mario's initial lives
 int World::getInitialLives() const {
     return initialLives;
 }
 
 // Returns a pointer to a specific level
 Level* World::getLevel(int index) {
     return levels[index];
 } 