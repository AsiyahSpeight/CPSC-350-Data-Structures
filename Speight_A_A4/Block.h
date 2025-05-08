/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA4: Blockchain Ledger
 */

/*
 * Block.h:
 * Header file for the Block class, defining the structure and behavior of a blockchain block.
 * It contains declarations for block attributes and public methods, including a custom hash
 * function to ensure each block’s uniqueness and chain linkage.
 */

 #ifndef BLOCK_H
 #define BLOCK_H
 
 #include <string>
 #include <iostream>
 
 class Block {
 public:
     int index;                 // Block's position in the chain
     std::string timestamp;     // Block creation time
     std::string data;          // Transaction/data stored in block
     std::string prevHash;      // Hash of the previous block
     std::string hash;          // This block’s hash
 
     Block* next;               // Pointer to next block
     Block* prev;               // Pointer to previous block
 
     Block(); // Default constructor
     Block(int idx, const std::string& ts, const std::string& dat, const std::string& prevHash); // Param constructor
 
     std::string computeHash();            // Computes hash from block contents
     std::string intToHexStream(int num);  // Converts int to hex string
 };
 
 #endif 