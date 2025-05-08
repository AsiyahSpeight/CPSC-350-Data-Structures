/*
Full name: Asiyah Speight
Student ID: 2357167
Chapman email: aspeight@chapman.edu
Course number and section: CPSC-350-04
Assignment: Programming Assignment 5 - Scare Games
*/ 

#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H

#include "TournamentNode.h"
#include "DOTFileGeneratorMethods.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
class TournamentTree {
public:
    TournamentTree();
    ~TournamentTree();

    void buildSingleElimination(std::vector<T*>& competitors);
    void buildDoubleElimination(std::vector<T*>& competitors);

    void saveTreeAsDot(const std::string& filename);
    void saveWinnerBracketToDot(const std::string& filename);
    void saveLoserBracketToDot(const std::string& filename);

    T* getFinalWinner();

private:
    TournamentNode<T>* root;
    TournamentNode<T>* winnerRoot;
    TournamentNode<T>* loserRoot;

    TournamentNode<T>* buildBracket(std::vector<T*>& competitors);
    TournamentNode<T>* buildDoubleElimFinal(TournamentNode<T>* winnerRoot, TournamentNode<T>* loserRoot);
    void collectLosers(TournamentNode<T>* node, std::vector<T*>& losers);
    void deleteTree(TournamentNode<T>* node);
};

// IMPLEMENTATION

template <typename T>
TournamentTree<T>::TournamentTree() : root(nullptr), winnerRoot(nullptr), loserRoot(nullptr) {}

template <typename T>
TournamentTree<T>::~TournamentTree() {
    deleteTree(root);
}

template <typename T>
void TournamentTree<T>::buildSingleElimination(std::vector<T*>& competitors) {
    root = buildBracket(competitors);
}

template <typename T>
void TournamentTree<T>::buildDoubleElimination(std::vector<T*>& competitors) {
    winnerRoot = buildBracket(competitors);

    std::vector<T*> losers;
    collectLosers(winnerRoot, losers);

    if (winnerRoot && winnerRoot->winner) {
        losers.erase(std::remove(losers.begin(), losers.end(), winnerRoot->winner), losers.end());
    }

    loserRoot = buildBracket(losers);
    root = buildDoubleElimFinal(winnerRoot, loserRoot);
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::buildBracket(std::vector<T*>& competitors) {
    if (competitors.empty()) return nullptr;

    std::vector<TournamentNode<T>*> round;
    for (T* comp : competitors)
        round.push_back(new TournamentNode<T>(comp));

    while (round.size() > 1) {
        std::vector<TournamentNode<T>*> nextRound;
        for (size_t i = 0; i < round.size(); i += 2) {
            if (i + 1 < round.size()) {
                T* winner = (*round[i]->winner > *round[i + 1]->winner)
                            ? round[i]->winner : round[i + 1]->winner;
                TournamentNode<T>* parent = new TournamentNode<T>(winner);
                parent->left = round[i];
                parent->right = round[i + 1];
                nextRound.push_back(parent);
            } else {
                nextRound.push_back(round[i]);
            }
        }
        round = nextRound;
    }

    return round.front();
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::buildDoubleElimFinal(TournamentNode<T>* winnerRoot, TournamentNode<T>* loserRoot) {
    T* finalWinner = (*winnerRoot->winner > *loserRoot->winner)
                     ? winnerRoot->winner : loserRoot->winner;
    TournamentNode<T>* finalMatch = new TournamentNode<T>(finalWinner);
    finalMatch->left = winnerRoot;
    finalMatch->right = loserRoot;
    return finalMatch;
}

template <typename T>
void TournamentTree<T>::collectLosers(TournamentNode<T>* node, std::vector<T*>& losers) {
    if (!node || !node->left || !node->right) return;

    if (node->left->winner != node->winner)
        losers.push_back(node->left->winner);
    else
        losers.push_back(node->right->winner);

    collectLosers(node->left, losers);
    collectLosers(node->right, losers);
}

template <typename T>
void TournamentTree<T>::saveTreeAsDot(const std::string& filename) {
    ::saveTreeAsDot(filename, root);
}

template <typename T>
void TournamentTree<T>::saveWinnerBracketToDot(const std::string& filename) {
    ::saveTreeAsDot(filename, winnerRoot);
}

template <typename T>
void TournamentTree<T>::saveLoserBracketToDot(const std::string& filename) {
    ::saveTreeAsDot(filename, loserRoot);
}

template <typename T>
T* TournamentTree<T>::getFinalWinner() {
    return root ? root->winner : nullptr;
}

template <typename T>
void TournamentTree<T>::deleteTree(TournamentNode<T>* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

#endif // TOURNAMENTTREE_H