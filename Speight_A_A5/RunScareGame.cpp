// RunScareGame.cpp

/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-04
 * Assignment: Programming Assignment 5
*/

#include "RunScareGame.h"
#include <fstream>
#include <sstream>
#include <iostream>
 
RunScareGame::RunScareGame() {}
RunScareGame::~RunScareGame() {}
 
void RunScareGame::run() {
     std::string filename, mode;
     std::cout << "Enter monster input filename: ";
     std::cin >> filename;
     std::cout << "Enter tournament mode (single/double): ";
     std::cin >> mode;
     runTournament(filename, mode);
}

// DO NOT RUN THIS FUNCTION AT ALL!!!!!!
// void RunScareGame::runTournament(const std::string& filename, const std::string& mode) {
//      std::vector<Monster*> monsters;
//      loadMonstersFromFile(filename, monsters);
 
//      TournamentTree<Monster> tree;
 
//      if (mode == "single") {
//          tree.buildSingleElimination(monsters);
//      } else if (mode == "double") {
//          tree.buildDoubleElimination(monsters);
//      } else {
//          std::cerr << "Invalid mode.\n";
//          cleanupMonsters(monsters);
//          return;
//      }
 
//      // Save bracket to DOT file (applies to both modes)
//      tree.saveTreeAsDot("tournament_bracket.dot");
 
//      cleanupMonsters(monsters);
// }

// run this one instead, fixed and debugged thanks to LLM ChatGPT, the prompt was "check and fix this code for so it can correctly allign with the assignment requirements."
void RunScareGame::runTournament(const std::string& filename, const std::string& mode) {
    std::vector<Monster*> monsters;
    loadMonstersFromFile(filename, monsters);

    TournamentTree<Monster> tree;

    if (mode == "single") {
        tree.buildSingleElimination(monsters);
        tree.saveTreeAsDot("single_bracket.dot");  // Save single elimination bracket
    } else if (mode == "double") {
        tree.buildDoubleElimination(monsters);
        tree.saveWinnerBracketToDot("winner_bracket.dot");  // Save winner bracket
        tree.saveLoserBracketToDot("loser_bracket.dot");    // Save loser bracket
    } else {
        std::cerr << "Invalid mode.\n";
        cleanupMonsters(monsters);
        return;
    }

    cleanupMonsters(monsters);
}
 
void RunScareGame::loadMonstersFromFile(const std::string& filename, std::vector<Monster*>& monsters) {
     std::ifstream infile(filename);
     if (!infile) {
         std::cerr << "Error opening " << filename << "\n";
         return;
     }
 
     std::string name;
     int power;
     while (infile >> name >> power) {
         monsters.push_back(new Monster(name, power));
     }
}
 
void RunScareGame::cleanupMonsters(std::vector<Monster*>& monsters) {
     for (Monster* m : monsters) delete m;
     monsters.clear();
}
 