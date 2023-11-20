#include "FlyingCreature.h"
#include <iostream>

FlyingCreature::FlyingCreature(std::string name, int healthPoints, int attackPoints)
    : Creature(name, healthPoints, attackPoints) {}

void FlyingCreature::attack(Creature& target) {
    // Perform a double attack
    target.reduceHealthPoints(getAttackPoints() * 2);

    // Fragilize wings and lose 10 health points
    reduceHealthPoints(10);

    if (isDead()) {
        std::cout << "The flying creature " << getName() << " is dead. Eduardo, the mad scientist, is notified." << std::endl;
    }
}

int FlyingCreature::getAttackPoints() const {
    return Creature::getAttackPoints();
}

FlyingCreature::~FlyingCreature() {
    std::cout << "The flying creature " << getName() << " is destroyed." << std::endl;
}
