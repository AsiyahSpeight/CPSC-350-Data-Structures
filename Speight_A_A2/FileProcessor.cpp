/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * FileProcessor.cpp - Implements file reading and logging functions.
 */

 #include "FileProcessor.h"
 #include "World.h"
 #include "Logger.h"
 #include <iostream>
 #include <fstream>
 
 using namespace std;
 
 FileProcessor::FileProcessor(const string& inputFile, const string& outputFile) {
     // Check if inputFile exists, if not create it as input.txt
     inFile.open(inputFile);
     if (!inFile) {
         cerr << "Input file not found, creating input.txt...\n";
         // Open inFile as an output file to create input.txt
         ofstream inFileCreate("input.txt");
         if (!inFileCreate) {
             cerr << "ERROR: CAN'T CREATE THE INPUT FILE input.txt\n";
             exit(1);
         }
         inFileCreate << "default level data\n"; // Example placeholder content
         inFileCreate.close(); // Close the created input.txt file
         inFile.open("input.txt"); // Reopen inFile as input stream after creation
     }
 
     // Check if outputFile exists, if not create it as output.txt
     outFile.open(outputFile);
     if (!outFile) {
         cerr << "Output file not found, creating output.txt...\n";
         // Open outFile as an output file to create output.txt
         ofstream outFileCreate("output.txt");
         if (!outFileCreate) {
             cerr << "ERROR: CAN'T CREATE THE OUTPUT FILE output.txt\n";
             exit(1);
         }
         outFileCreate << "Game logs start here...\n"; // Example placeholder content
         outFileCreate.close(); // Close the created output.txt file
         outFile.open("output.txt"); // Reopen outFile as output stream after creation
     }
 }
 
 // Function to read the input file and create a World object with the data
 World FileProcessor::realWorld() {
     int numLevels, gridSize, initialLives;
 
     // Read data from the input file
     inFile >> numLevels >> gridSize >> initialLives;
 
     // Create and return a World object using the data from the input file
     return World(numLevels, gridSize, initialLives);
 }
 
 // Define the writeLog function to log to output.txt
 void FileProcessor::writeLog(const string& logEntry) {
     if (outFile.is_open()) {
         outFile << logEntry << endl;  // Write log entry to the output file
     } else {
         cerr << "ERROR: Unable to write to the output file!" << endl;
     }
 }
 
 FileProcessor::~FileProcessor() {
     if (inFile.is_open()) inFile.close();
     if (outFile.is_open()) outFile.close();
 } 