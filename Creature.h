#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
private:
    std::string name;
    int healthPoints;
    int attackPoints;

public:
    Creature(std::string name = "Creature", int healthPoints = 100, int attackPoints = 50);

    virtual void attack(Creature& target);

    bool isDead() const;

    std::string getName() const;
    int getHealthPoints() const;
    int getAttackPoints() const;

    void reduceHealthPoints(int amount);
    void increaseHealthPoints(int amount);

    virtual ~Creature();
};

#endif // CREATURE_H
