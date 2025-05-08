/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Logger.cpp - Implements the Logger class for logging game events.
 * This file ensures that the game's progress is logged in the correct format.
 */

#include "Logger.h"
#include <iostream>
#include <string>

using namespace std;

// begin with the constructor for the logger class, this opens the output file for logging game events
Logger::Logger(const std::string& outputFile) {
    outFile.open(outputFile);
    if (!outFile) {
        cerr << "ERROR: CANNOT OPEN LOG FILE: " << outputFile << "\n";
        exit(1);
    }
}

// after we write the destructor for the logger class, this closes the output file when the logger object is destroyed
Logger::~Logger() {
    if (outFile.is_open()) outFile.close();
}

// this function logs the initial level grid layout
void Logger::logInitialGrid(char grid[][5], int gridSize) {
    if (outFile.is_open()) {
        for (int r = 0; r < gridSize; r++) {
            for (int c = 0; c < gridSize; c++) {
                outFile << grid[r][c];
            }
            outFile << "\n"; // used to seperate the rows in the output file
        }
        outFile << "==========\n"; // used to seperate the grid layout from the game events
    }
}

// the following logs marios strating position in the level
void Logger::logMarioStart(int row, int col) { 
    if (outFile.is_open()) {
        outFile << "Mario is starting in position: (" << row << "," << col << ")\n";
        outFile << "==========\n";
    }
}

// this logs the game events, including Mario's position, power level, action, lives, coins, and next move
void Logger::logMove(int level, int row, int col, int powerLevel, const char* action, int lives, int coins, char nextMove) {
    if (outFile.is_open()) {
        outFile << "Level: " << level << ". Mario is at position: (" << row << "," << col << "). ";
        outFile << "Mario is at power level " << powerLevel << ". " << action << ". ";
        outFile << "Mario has " << lives << " lives left. Mario has " << coins << " coins. ";
        outFile << "Mario will move " << (nextMove == 'U' ? "UP" : nextMove == 'D' ? "DOWN" : nextMove == 'L' ? "LEFT" : "RIGHT") << ".\n";
        outFile << "==========\n";
    }
}

// lastly this logs the final game result, indicating if Mario won or lost
void Logger::logFinalResult(bool won) {
    if (outFile.is_open()) {
        if (won) {
            outFile << "MARIO WON AND SAVED THE PRINCESS! :)\n";
        } else {
            outFile << "MARIO LOST AND THE PRINCESS IS IN ANOTHER CASTLE! :(\n";
        }
    }
}