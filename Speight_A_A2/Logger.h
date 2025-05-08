/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Logger.h - Handles writing game events to the output file.
 * This includes Mario's movements, interactions, and final results.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
    public:
        Logger(const std::string& outputFile); // constructor -- Initializes the logger with the output file
        ~Logger(); // destructor
        
        void logInitialGrid(char grid[][5], int gridSize); // logs the inital grid setup before mario starts moving
        void logMarioStart(int row, int col); // logs the starting position of mario
        void logMove(int level, int row, int col, int powerLevel, const char* action, int lives, int coins, char nextMove); // logs mario's movement and the results of the move
        void logFinalResult(bool won); // logs the final result of the game whether he wins or loses.
    
        private:
        std::ofstream outFile; // output file stream
};

#endif