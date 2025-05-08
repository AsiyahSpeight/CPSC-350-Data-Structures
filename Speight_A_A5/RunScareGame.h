/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA5: Scare Games
 */

#ifndef RUNSCAREGAME_H
#define RUNSCAREGAME_H
 
#include "Monster.h"
#include "TournamentTree.h"
#include <vector>
#include <string>
 
class RunScareGame {
public:
     RunScareGame();
     ~RunScareGame();
 
     void run();
     void runTournament(const std::string& filename, const std::string& mode);
 
private:
     void loadMonstersFromFile(const std::string& filename, std::vector<Monster*>& monsters);
     void cleanupMonsters(std::vector<Monster*>& monsters);
};
 
#endif 