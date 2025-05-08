/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * FileProcessor.h - Handles reading the game input file and writing logs to the output file.
 */

 #ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "World.h"
#include <fstream>
#include <iostream>
#include <string>

class FileProcessor {
    public:
        FileProcessor(const std::string& inputFile, const std::string& outputFile); // constructor
        ~FileProcessor(); // destructor

        World realWorld(); // Reads the input file and constructs the game world
        void writeLog(const std::string& logEntry); // Write a log entry to the output file

    private:
        std::ifstream inFile; // Input file stream
        std::ofstream outFile; // Output file stream
};

#endif