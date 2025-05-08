/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Mario.h - Defines the main character, Mario, who navigates levels,
 * collects items, fights enemies, and tracks game progress.
 */

 #ifndef MARIO_H
 #define MARIO_H
 
 class Mario {
     public:
         Mario(int initialLives); // Constructor to initialize Mario with a given number of lives
 
         void collectCoin(); // Collect coins and gain extra life every 20 coins
         void eatMushroom(); // Increase Mario's power level by 1 (up to max of 2)
         void fightEnemy(char enemyType); // Fight an enemy based on type (Goomba, Koopa, etc.)
         void loseLife(); // Decrease Mario's life and reset power level to 0
         void move(char direction, int gridSize); // Move Mario on the grid
         void warp(int newX, int newY); // Teleport Mario to a specific position (warp pipe)
 
         bool isAlive() const; // Check if Mario is alive (has lives left)
         bool isDead() const; // Check if Mario is dead (out of lives)
 
         int getPowerLevel() const; // Get Mario's current power level
         int getLives() const; // Get Mario's current lives
         int getCoins() const; // Get Mario's current coin count
         int getX() const; // Get Mario's current X position (row)
         int getY() const; // Get Mario's current Y position (column)
 
     private:
         int lives; // Mario's current lives
         int powerLevel; // Mario's current power level
         int coins; // Number of coins Mario has collected
         int posX, posY; // Mario's current position on the grid (X, Y)
 };
 
 #endif 