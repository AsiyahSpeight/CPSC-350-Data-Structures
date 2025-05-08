/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA4: Blockchain Ledger
 */

/*
 * Blockchain.h:
 * Header file for the Blockchain class. This file declares all public methods for managing
 * a chain of Block objects. It supports adding new blocks, validating integrity, displaying
 * the chain, and saving/loading from files.
 */

 #ifndef BLOCKCHAIN_H
 #define BLOCKCHAIN_H
 
 #include "Block.h"
 
 class Blockchain {
 private:
     Block* head;  // Genesis block
     Block* tail;  // Last block in the chain
     int size;     // Number of blocks
 
     std::string currentTimeStamp();       // Gets current time as string
     void printBlock(Block* block);        // Helper to display one block
 
 public:
     Blockchain(); // Constructor that creates Genesis block
     ~Blockchain(); // Destructor to free memory
 
     void addBlock(const std::string& data);             // Add new block
     void displayChain();                               // Display all blocks
     bool validateChain();                              // Verify hash chain
     void saveToFile(const std::string& filename);      // Save blockchain to file
     void loadFromFile(const std::string& filename);    // Load blockchain from file
 };
 
 #endif 