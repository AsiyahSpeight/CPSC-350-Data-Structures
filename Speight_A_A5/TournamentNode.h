/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA5: Scare Games
 */

// TournamentNode.h

#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

template <typename T>
class TournamentNode {
public:
    T* winner;
    TournamentNode* left;
    TournamentNode* right;

    TournamentNode(T* winner) : winner(winner), left(nullptr), right(nullptr) {}
    ~TournamentNode() {
        delete left;
        delete right;
    }
};

#endif