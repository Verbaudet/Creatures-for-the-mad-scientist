#include "Creature.h"
#include "FlyingCreature.h"
#include "BloodyCreature.h"

#include <iostream>

Creature::Creature(std::string name, int healthPoints, int attackPoints)
    : name(name), healthPoints(std::min(healthPoints, 100)), attackPoints(std::min(attackPoints, 50)) {}

void Creature::attack(Creature& target) {
    target.reduceHealthPoints(attackPoints);

    if (target.isDead()) {
        std::cout << "La creature " << target.name << " est morte. Un message est envoye a Eduardo, le savant fou." << std::endl;
    }
}

bool Creature::isDead() const {
    return healthPoints <= 0;
}

std::string Creature::getName() const {
    return name;
}

int Creature::getHealthPoints() const {
    return healthPoints;
}

int Creature::getAttackPoints() const {
    return attackPoints;
}

void Creature::reduceHealthPoints(int amount) {
    healthPoints -= amount;
}

void Creature::increaseHealthPoints(int amount) {
    healthPoints += amount;
}

Creature::~Creature() {
    std::cout << "La creature " << name << " est detruite." << std::endl;
}
