/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA4: Blockchain Ledger
 */

/*
 * Block Class:
 * This class represents a single block in a blockchain. Each block contains an index indicating
 * its position in the chain, a timestamp of when it was created, a string of data (representing
 * transactions or messages), a hash of the previous block for linkage, and a hash of its own
 * contents to ensure integrity. If any part of the block changes, the hash will change,
 * thereby breaking the chain and exposing tampering.
 */

 #include "Block.h"
 #include <sstream>
 
 // Default constructor
 Block::Block() {
     next = nullptr;
     prev = nullptr;
 }
 
 // Constructor: initializes fields and computes the hash
 Block::Block(int idx, const std::string& ts, const std::string& dat, const std::string& prevHash)
     : index(idx), timestamp(ts), data(dat), prevHash(prevHash) {
     hash = computeHash();
     next = nullptr;
     prev = nullptr;
 }
 
 // Converts an integer to a hexadecimal string
 std::string Block::intToHexStream(int num) {
     std::stringstream ss;
     ss << std::hex << num;
     return ss.str();
 }
 
 // Computes hash by summing ASCII values of block content and converting to hex
 std::string Block::computeHash() {
     std::string content = std::to_string(index) + timestamp + data + prevHash;
     int asciiSum = 0;
     for (char c : content) {
         asciiSum += static_cast<int>(c);
     }
     return intToHexStream(asciiSum);
 } 