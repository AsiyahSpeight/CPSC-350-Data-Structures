/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA4: Blockchain Ledger
 */

/*
 * User Interface & Main Function:
 * This file serves as the main driver for the blockchain program. It presents a simple 
 * console-based menu for interacting with the blockchain. Users can add blocks, view the 
 * entire chain, validate its integrity, save it to a file, or load from an existing file. 
 * This allows for simulating real-world blockchain interactions in a straightforward way.
 */

 #include "Blockchain.h"
#include <iostream>
#include <fstream> // Needed for file writing

// Writes a valid blockchain file matching the sample output
void writeValidFile() {
    std::ofstream out("myBlockChain.txt");
    out << "0|Sat Mar 22 06:15:37 2025|Genesis Block|0|ad8\n";
    out << "1|Sat Mar 22 06:15:41 2025|Elia sent Erik 1000 Panther Coins|ad8|11b7\n";
    out << "2|Sat Mar 22 06:15:54 2025|Erik sent Elizabeth 88 Panther Coins|11b7|1386\n";
    out << "3|Sat Mar 22 06:16:17 2025|Elizabeth sent Elia 45 Panther Coins|1386|1347\n";
    out.close();
    std::cout << "✅ Valid blockchain file written to: myBlockChain.txt\n";
}

// Writes a tampered blockchain file (hash mismatch on block 2)
void writeTamperedFile() {
    std::ofstream out("myBlockChain.txt");
    out << "0|Sat Mar 22 06:15:37 2025|Genesis Block|0|ad8\n";
    out << "1|Sat Mar 22 06:15:41 2025|Elia sent Erik 1000 Panther Coins|ad8|11b7\n";
    out << "2|Sat Mar 22 06:15:54 2025|CHANGED|11b7|1386\n"; //  Invalid data
    out << "3|Sat Mar 22 06:16:17 2025|Elizabeth sent Elia 45 Panther Coins|1386|1347\n";
    out.close();
    std::cout << "⚠️ Tampered blockchain file written to: myBlockChain.txt\n";
}

int main() {
    Blockchain bc; // Initialize blockchain
    int choice;
    std::string input;

    // Menu loop
    while (true) {
        std::cout << "Welcome to your Panther Blockchain Ledger:\n";
        std::cout << "1. Add a New Block\n";
        std::cout << "2. Display the Blockchain\n";
        std::cout << "3. Validate the Blockchain\n";
        std::cout << "4. Save Blockchain to File\n";
        std::cout << "5. Load Blockchain from File\n";
        std::cout << "6. Exit\n";
        std::cout << "7. Write VALID Test File\n";
        std::cout << "8. Write TAMPERED Test File\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from buffer

        switch (choice) {
            case 1:
                std::cout << "Enter block data: ";
                getline(std::cin, input);
                bc.addBlock(input);
                break;
            case 2:
                bc.displayChain();
                break;
            case 3:
                bc.validateChain();
                break;
            case 4:
                std::cout << "Enter filename to save the blockchain: ";
                getline(std::cin, input);
                bc.saveToFile(input);
                break;
            case 5:
                std::cout << "Enter filename to load the blockchain: ";
                getline(std::cin, input);
                bc.loadFromFile(input);
                break;
            case 6:
                std::cout << "Exiting... BYE BYE\n";
                return 0;
            case 7:
                writeValidFile();
                break;
            case 8:
                writeTamperedFile();
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }

    return 0;
}