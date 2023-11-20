#include "BloodyCreature.h"
#include <iostream>

BloodyCreature::BloodyCreature(std::string name, int healthPoints, int attackPoints)
    : Creature(name, healthPoints, attackPoints) {}

void BloodyCreature::attack(Creature& target) {
    // Perform a bloody attack (deals half damage but heals)
    int damage = getAttackPoints() / 2;
    target.reduceHealthPoints(damage);
    increaseHealthPoints(std::min(damage, getHealthPoints()));

    if (isDead()) {
        std::cout << "The bloody creature " << getName() << " is dead. Eduardo, the mad scientist, is notified." << std::endl;
    }
}

int BloodyCreature::getAttackPoints() const {
    return Creature::getAttackPoints();
}

BloodyCreature::~BloodyCreature() {
    std::cout << "The bloody creature " << getName() << " is destroyed." << std::endl;
}
