/*
 * Full name: Asiyah Speight
 * Worked in partnership with: Carolina and Kevin
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA2: Not So Super Mario Bros.
 *
 * Mario.cpp - Implements Mario's attributes, movement, power-ups, and combat logic.
 */

 #include "Mario.h"
 #include <iostream>
 #include <cstdlib> // For rand() function
 
 using namespace std;
 
 // Constructor: Initializes Mario's attributes with given starting lives
 Mario::Mario(int initialLives) {
     lives = initialLives;
     powerLevel = 0; // Initial power level
     coins = 0; // Initial coins
     posX = 0; // Initial X position
     posY = 0; // Initial Y position
 }
 
 // Fight an enemy: Decreases power level if Mario loses, or decreases life if no power left
 void Mario::fightEnemy(char enemyType) {
     // Determine win chance based on enemy type
     int winChance = (enemyType == 'g') ? 80 : (enemyType == 'k') ? 65 : 50;
     int outcome = rand() % 100; // Generate random outcome between 0-99
 
     // Check if Mario wins or loses the fight
     if (outcome < winChance) {
         cout << "MARIO DEFEATED THE ENEMY! :)" << endl;
     } else {
         cout << "MARIO LOST THE FIGHT :(" << endl;
         if (powerLevel > 0) {
             powerLevel--; // Decrease power level if Mario has power
         } else {
             loseLife(); // If no power, lose a life
         }
     }
 }
 
 // Decrease Mario's life and reset power level to 0
 void Mario::loseLife() {
     lives--;
     powerLevel = 0; // Reset power level to 0 when life is lost
 }
 
 // Collect a coin: Every 20 coins grants Mario an extra life
 void Mario::collectCoin() {
     coins++;
     if (coins == 20) {
         lives++;  // Extra life for every 20 coins
         coins = 0; // Reset coin count after gaining life
     }
 }
 
 // Increase Mario's power level by 1 (up to a max of 2)
 void Mario::eatMushroom() {
     if (powerLevel < 2) powerLevel++; // Increase power level, but cap at 2
 }
 
 // Move Mario based on the given direction (up, down, left, or right)
 void Mario::move(char direction, int gridSize) {
     if (direction == 'U') posX = (posX - 1 + gridSize) % gridSize; // Move up (wrap around grid)
     if (direction == 'D') posX = (posX + 1) % gridSize; // Move down (wrap around grid)
     if (direction == 'L') posY = (posY - 1 + gridSize) % gridSize; // Move left (wrap around grid)
     if (direction == 'R') posY = (posY + 1) % gridSize; // Move right (wrap around grid)
 }
 
 // Teleport Mario to a specific position (used for warp pipes)
 void Mario::warp(int newX, int newY) {
     posX = newX;
     posY = newY;
 }
 
 // Check if Mario is dead (out of lives)
 bool Mario::isDead() const {
     return lives <= 0;
 }
 