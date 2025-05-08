/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA4: Blockchain Ledger
 */

/*
 * Blockchain Class:
 * This class manages a sequence of blocks, starting with a genesis block. It supports core
 * blockchain operations such as adding new blocks, validating the integrity of the chain,
 * and performing file input/output. Each new block is linked by storing the hash of the 
 * previous block, ensuring immutability. Any tampering with a block invalidates the chain.
 */

 #include "Blockchain.h"
 #include <iostream>
 #include <fstream>
 #include <ctime>
 
 // Constructor — creates Genesis block
 Blockchain::Blockchain() {
     std::string ts = currentTimeStamp();
     Block* genesis = new Block(0, ts, "Genesis Block", "0");
     head = tail = genesis;
     size = 1;
 
     std::cout << " Genesis Block Created \n";
     printBlock(genesis);
 }
 
 // destructor to travserse the list and delete each block
 Blockchain::~Blockchain() {
    Block* current = head;
    while (current != nullptr) {
        Block* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}


 // Get current time as string
 std::string Blockchain::currentTimeStamp() {
     time_t now = time(0);
     return std::string(ctime(&now)); // includes newline
 }
 
 // Print a single block
 void Blockchain::printBlock(Block* block) {
     std::cout << "Index: " << block->index << "\n";
     std::cout << "Timestamp: " << block->timestamp;
     std::cout << "Data: " << block->data << "\n";
     std::cout << "Previous Hash: " << block->prevHash << "\n";
     std::cout << "Hash: " << block->hash << "\n\n";
 }
 
 // Add a new block to the end of the chain
 void Blockchain::addBlock(const std::string& data) {
     std::string ts = currentTimeStamp();
     Block* newBlock = new Block(size, ts, data, tail->hash);
 
     newBlock->prev = tail;
     tail->next = newBlock;
     tail = newBlock;
     ++size;
 
     std::cout << " New Block Added \n";
     printBlock(newBlock);
 }
 
 // Traverse the list and display all blocks
 void Blockchain::displayChain() {
     std::cout << " Blockchain State\n";
     Block* current = head;
     while (current != nullptr) {
         printBlock(current);
         current = current->next;
     }
 }
 
 // Check that hashes and links are valid
 bool Blockchain::validateChain() {
     std::cout << "Performing blockchain validation...\n";
     Block* current = head->next;
 
     while (current != nullptr) {
         if (current->prevHash != current->prev->hash) {
             std::cout << "Block " << current->index << " has mismatched previous hash!\n";
             std::cout << "Result: Blockchain is invalid! \n";
             return false;
         }
         if (current->hash != current->computeHash()) {
             std::cout << "Block " << current->index << " has an invalid current hash!\n";
             std::cout << "Result: Blockchain is invalid! \n";
             return false;
         }
         current = current->next;
     }
 
     std::cout << "Result: Blockchain is valid \n";
     return true;
 }
 
 // Write blockchain to file
 void Blockchain::saveToFile(const std::string& filename) {
     std::ofstream out(filename);
     Block* current = head;
     while (current != nullptr) {
         out << current->index << "|"
             << current->timestamp << "|"
             << current->data << "|"
             << current->prevHash << "|"
             << current->hash << "\n";
         current = current->next;
     }
     out.close();
     std::cout << "Blockchain saved to file: " << filename << "\n";
 }
 
 // Load blockchain from file and reconstruct the linked list
 void Blockchain::loadFromFile(const std::string& filename) {
     std::ifstream in(filename);
     if (!in) {
         std::cout << "Error: File not found.\n";
         return;
     }
 
     head = tail = nullptr;
     size = 0;
 
     std::string line;
     while (getline(in, line)) {
         if (line.empty()) continue;
 
         size_t pos1 = line.find("|");
         size_t pos2 = line.find("|", pos1 + 1);
         size_t pos3 = line.find("|", pos2 + 1);
         size_t pos4 = line.find("|", pos3 + 1);
 
         int idx = std::stoi(line.substr(0, pos1));
         std::string ts = line.substr(pos1 + 1, pos2 - pos1 - 1);
         std::string data = line.substr(pos2 + 1, pos3 - pos2 - 1);
         std::string prev = line.substr(pos3 + 1, pos4 - pos3 - 1);
         std::string hash = line.substr(pos4 + 1);
 
         Block* block = new Block(idx, ts, data, prev);
         block->hash = hash;
 
         if (head == nullptr) {
             head = tail = block;
         } else {
             tail->next = block;
             block->prev = tail;
             tail = block;
         }
 
         ++size;
     }
 
     in.close();
     std::cout << "Blockchain loaded from file: " << filename << "\n";
 } 