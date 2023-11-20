#ifndef BLOODY_CREATURE_H
#define BLOODY_CREATURE_H

#include "Creature.h"

class BloodyCreature : public Creature {
public:
    BloodyCreature(std::string name = "BloodyCreature", int healthPoints = 50, int attackPoints = 25);

    void attack(Creature& target) override;

    // Accessor for attackPoints
    int getAttackPoints() const;

    ~BloodyCreature();
};

#endif // BLOODY_CREATURE_H
