/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA5: Scare Games
 */

 #ifndef DOTFILEGENERATORMETHODS_H
 #define DOTFILEGENERATORMETHODS_H
 
 #include <fstream>
 #include <string>
 #include <iostream>
 #include "TournamentNode.h"
 
 template <typename T>
 void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID);
 
 template <typename T>
 void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
     std::ofstream file(filename);
     if (!file.is_open()) {
         std::cerr << "Failed to open file for DOT output: " << filename << "\n";
         return;
     }
 
     file << "digraph TournamentTree {\n";
     int nodeID = 0;
     saveTreeAsDotHelper(rootNode, file, nodeID);
     file << "}\n";
     file.close();
 }
 
 template <typename T>
 void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
     if (!node) return;
 
     int currentID = nodeID++;
     file << "    node" << currentID << " [label=\"" << node->winner->getName()
          << " (Power: " << node->winner->getScreamPower() << ")\"];\n";
 
     if (node->left) {
         int leftID = nodeID;
         saveTreeAsDotHelper(node->left, file, nodeID);
         file << "    node" << currentID << " -> node" << leftID << ";\n";
     }
 
     if (node->right) {
         int rightID = nodeID;
         saveTreeAsDotHelper(node->right, file, nodeID);
         file << "    node" << currentID << " -> node" << rightID << ";\n";
     }
 }
 
 #endif 