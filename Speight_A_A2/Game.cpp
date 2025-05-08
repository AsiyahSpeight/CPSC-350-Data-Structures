/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Game.cpp - Implements the main game logic, handling level progression,
 * enemy encounters, and logging Mario's journey.
 */

#include "Game.h"
#include <iostream>

using namespace std;

// Constructor -- initializes the game world and loads game settings from the input file
Game::Game(FileProcessor& fileProcessor, Logger& logger) : logger(logger), gameOver(false), mario(3) {
    initializeGame(fileProcessor);
}

// Reads input file to set up game parameters (number of levels, grid size, etc.)
void Game::initializeGame(FileProcessor& fileProcessor) {
    World world = fileProcessor.realWorld(); // This uses the realWorld function
    numLevels = world.getNumLevels();
    gridSize = world.getGridSize();

    // Validate the sizes
    if (numLevels <= 0 || gridSize <= 0) {
        cerr << "ERROR: Invalid values for numLevels or gridSize: " << numLevels << ", " << gridSize << endl;
        exit(1);
    }

    // Initialize Mario with the starting number of lives
    mario = Mario(world.getInitialLives());

    // Allocates levels dynamically
    levels = new Level*[numLevels];
    for (int i = 0; i < numLevels; i++) {
        levels[i] = new Level(gridSize);
    }
}

// Runs the game simulation
void Game::runSimulation() {
    for (int i = 0; i < numLevels; i++) {
        processMarioActions(i);  // Process actions for each level
        if (gameOver) {
            cout << "Game Over! Mario lost." << endl;
            break;
        }
    }
}

// Placeholder for processing Mario's actions in each level
void Game::processMarioActions(int levelIndex) {
    // Placeholder: handle Mario's actions for each level
    cout << "Processing actions for level " << levelIndex + 1 << endl;
}

// Starts the game
void Game::startGame() {
    runSimulation();
}

// Destructor to clean up dynamically allocated memory
Game::~Game() {
    for (int i = 0; i < numLevels; i++) {
        delete levels[i];
    }
    delete[] levels;
}