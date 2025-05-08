/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * main.cpp - Entry point of the game. Initializes game components and starts the simulation.
 */

 #include "Game.h"
#include <iostream>
#include <fstream>
#include <ctime> // Include for srand to seed random number generation

using namespace std;

int main(int argc, char* argv[]) {
    // Ensure correct number of command line arguments (input and output file paths)
    if (argc != 3) {
        cerr << "USAGE: ./game input.txt output.txt" << endl;
        return 1; // Exit with error code if arguments are incorrect
    }

    // Check if the input file exists, if not, create spec.txt
    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "Input file not found, creating spec.txt...\n";
        ofstream inFileCreate("spec.txt");
        if (!inFileCreate) {
            cerr << "ERROR: CAN'T CREATE THE INPUT FILE spec.txt\n";
            return 1;
        }
        inFileCreate << "default level data\n"; // Example placeholder content
    }

    // Check if the output file exists, if not, create log.txt
    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "Output file not found, creating log.txt...\n";
        outFile.open("log.txt", ios::out);  // Create log.txt if not found
        if (!outFile) {
            cerr << "ERROR: CAN'T CREATE THE OUTPUT FILE log.txt\n";
            return 1;
        }
        outFile << "Game logs start here...\n"; // Example placeholder content
    }

    srand(time(0));  // Seed the random number generator to ensure different random values each run

    // Initialize file processor and game logger
    FileProcessor fileProcessor(argv[1], argv[2]);
    Logger logger(argv[2]);

    // Create and start the game
    Game game(fileProcessor, logger);
    game.startGame();

    return 0; // Return success code
}