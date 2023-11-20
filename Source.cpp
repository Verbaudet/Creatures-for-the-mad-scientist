#include "Creature.h"
#include "FlyingCreature.h"
#include "BloodyCreature.h"
#include <iostream>
#include <cstdlib> // Pour la fonction rand()
#include <cctype>  // Pour la fonction std::tolower
#include <limits>  // Pour std::numeric_limits

#ifdef _WIN32
#include <conio.h> // Pour la fonction _getch()
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#endif
}

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

void displayCreatureInfo(const Creature& creature) {
    std::cout << creature.getName() << " - Points de vie: " << creature.getHealthPoints() << ", Attaque: " << creature.getAttackPoints() << std::endl;
}

int main() {
    std::cout << "Appuyez sur E pour commencer le combat...\n";
    BloodyCreature creature1("Vampire des tenebres qui tuent", 80, 40);
    FlyingCreature creature2("Flapflap chauve-souris", 90, 2);

    std::cout << creature1.getName() << " - Points de vie: " << creature1.getHealthPoints() << ", Attaque: " << creature1.getAttackPoints() << std::endl;
    std::cout << creature2.getName() << " - Points de vie: " << creature2.getHealthPoints() << ", Attaque: " << creature2.getAttackPoints() << std::endl;
    printSeparator();

    char startKey;
    std::cin >> startKey;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::tolower(startKey) != 'e') {
        std::cout << "Combat annulé. Fin du programme.\n";
        return 0;
    }

combatLoop:
    while (!creature1.isDead() && !creature2.isDead()) {
        std::cout << "\nTour de " << creature1.getName() << " (Points de vie: " << creature1.getHealthPoints() << ")\n";
        creature1.attack(creature2);
        std::cout << creature1.getName() << " attaque " << creature2.getName() << ". Points de vie restants: " << creature2.getHealthPoints() << "\n";
        printSeparator();

        if (creature2.isDead()) {
            std::cout << creature2.getName() << " est morte!\n";
            break;
        }

        std::cout << "\nTour de " << creature2.getName() << " (Points de vie: " << creature2.getHealthPoints() << ")\n";
        creature2.attack(creature1);
        std::cout << creature2.getName() << " attaque " << creature1.getName() << ". Points de vie restants: " << creature1.getHealthPoints() << "\n";
        printSeparator();

        if (creature1.isDead()) {
            std::cout << creature1.getName() << " est morte!\n";
            break;
        }

        std::cout << "\nAppuyez sur E pour continuer, I pour afficher les informations, ou Q pour quitter...\n";
        char input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (std::tolower(input)) {
        case 'e':
            clearScreen();
            goto combatLoop;
            break;

        case 'i':
            std::cout << "Informations des creatures :\n";
            displayCreatureInfo(creature1);
            displayCreatureInfo(creature2);
            break;

        case 'q':
            std::cout << "Vous avez quitte le combat.\n";
            return 0;

        default:
            std::cout << "Commande non reconnue. fais un effort stp.\n";
        }
    }

    std::cout << "\nFin du combat.\n";

    return 0;
}