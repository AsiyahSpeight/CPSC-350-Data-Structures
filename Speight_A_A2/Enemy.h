/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Enemy.h - Defines the base class for all enemies, including Goomba, Koopa, and Boss.
 * Each enemy has different behavior and win probability in combat.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Mario.h"

class Enemy {
    protected: // cannot be accessed directly from outside the, it can be accessed by derived class (subclass)
        int winProbability; // probability of mario winning the fight (0 - 100)
    
    public:
        Enemy(int winChance);
        virtual ~Enemy() {}; // the destructor, the "virtual" key word ensures that when an enemy object is deleted through a pointer to the base class 

        virtual char getSymbol() const = 0; // pure virtual function, must be implemented by derived classes
        virtual bool fight(Mario& mario); // returns true if mario wins, false if enemy wins
};

// Goomba enemy class
class Goomba : public Enemy {
    public:
        Goomba(); // constructor
        char getSymbol() const override; // override the base class function
};

// Koopa enemy class
class Koopa : public Enemy {
    public:
        Koopa(); // constructor
        char getSymbol() const override; // override the base class function
};

// Boss enemy class (Mario must fight to progress to next level)
class Boss : public Enemy {
    public:
        Boss(); // constructor
        char getSymbol() const override; // override the base class function
        bool fight (Mario& mario) override;
};

#endif