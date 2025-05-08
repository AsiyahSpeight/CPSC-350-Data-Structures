/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA5: Scare Games
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

class Monster {
private:
    std::string name;
    int screamPower;

public:
    Monster(const std::string& name, int screamPower);
    ~Monster() = default;

    std::string getName() const;
    int getScreamPower() const;

    bool operator>(const Monster& other) const;
    bool operator==(const Monster& other) const;

    std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const Monster& m);

#endif