/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Game.h - Manages the overall game logic, including initializing the world,
 * running the simulation, and handling game progression.
 */

 #ifndef GAME_H
 #define GAME_H
 
 #include "Mario.h"
 #include "Level.h"
 #include "Enemy.h"
 #include "Logger.h"
 #include "FileProcessor.h"
 
 class Game {
     public:
         Game(FileProcessor& fileProcessor, Logger& logger); // the constructor which initializes game settings from input file and prepares logger
 
         ~Game(); // the destructor which cleans up memory and closes allocated memory
 
         void initializeGame(FileProcessor& fileProcessor); // reads the game settings from the input file
         void runSimulation(); // runs the main simulation loop mario wins or loses
         void processMarioActions(int levelIndex); // handles marios actions for each level
         void startGame(); // starts the game
     
     private:
         int numLevels; // number of levels in the game
         int gridSize; // grid size for each level (NxN)
         Mario mario; // main character of the game (mario)
         Logger& logger; // logger to track game events
         Level** levels; // pointer to dynamically allocated level array
         bool gameOver; // flag to indicate if the game has ended
 };
 
 #endif 