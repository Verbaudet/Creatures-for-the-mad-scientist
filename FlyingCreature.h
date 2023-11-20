#ifndef FLYING_CREATURE_H
#define FLYING_CREATURE_H

#include "Creature.h"

class FlyingCreature : public Creature {
public:
    FlyingCreature(std::string name = "FlyingCreature", int healthPoints = 100, int attackPoints = 50);

    void attack(Creature& target) override;

    // Accessor for attackPoints
    int getAttackPoints() const;

    ~FlyingCreature();
};

#endif // FLYING_CREATURE_H
