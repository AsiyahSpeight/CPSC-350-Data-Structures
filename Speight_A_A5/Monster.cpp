/*
 * Full name: Asiyah Speight
 * Student ID: 2357167
 * Chapman email: aspeight@chapman.edu
 * Course number and section: CPSC 350-02
 * Assignment: PA5: Scare Games
*/

#include "Monster.h"

Monster::Monster(const std::string& name, int screamPower) : name(name), screamPower(screamPower) {}

std::string Monster::getName() const {
    return name;
}

int Monster::getScreamPower() const {
    return screamPower;
}

bool Monster::operator>(const Monster& other) const {
    return this->screamPower > other.screamPower;
}

bool Monster::operator==(const Monster& other) const {
    return this->name == other.name && this->screamPower == other.screamPower;
}

std::string Monster::toString() const {
    return name + " (" + std::to_string(screamPower) + ")";
}

std::ostream& operator<<(std::ostream& os, const Monster& m) {
    os << m.toString();
    return os;
}