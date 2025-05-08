/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Enemy.cpp - Implements enemy behavior, including Goomba, Koopa, and Boss.
 * Each enemy has a different probability of Mario winning in battle.
 */

#include "Enemy.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// base enemy constructor
Enemy::Enemy(int winChance) : winProbability(winChance) {}

// regular enemy fight logic
bool Enemy::fight(Mario& mario) {
    int outcome = rand() % 100; // generates a random number (0 - 99)
    if (outcome < winProbability) {
        cout << "Mario defeated the " << getSymbol() << "!\n";
        return true;
    } else {
        cout << "Mario lost to the " << getSymbol() << "!\n";
        mario.fightEnemy(getSymbol());
        return false;
    }
}

// goomba specific implementation
Goomba::Goomba() : Enemy(80) {} // 80% win rate 
char Goomba::getSymbol() const {
    return 'g';
}

// koopa specific implementation
Koopa::Koopa() : Enemy(60) {} // 60% win rate
char Koopa::getSymbol() const {
    return 'k';
}

// boss specific implementation (mario must fight till he either eins or dies)
Boss::Boss() : Enemy(50) {} // 50% win rate
char Boss::getSymbol() const {
    return 'b';
}

bool Boss::fight(Mario& mario) {
    cout << "MARIO IS FIGHTING THE BOSS!\n";

    while (true) {
        int outcome = rand() % 100;
        if (outcome < winProbability) {
            cout << "MARIO HAS DEFEATED THE BOSS!\n";
            return true;
        } else {
            cout << "MARIO LOST TO THE BOSS!\n";
            mario.fightEnemy('b');

            if (mario.isDead()) {
                cout << "GAME OVER! Mario has been defeated by the BOSS.\n";
                return false;
            }
        }
    }
}