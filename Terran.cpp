#include "Terran.h"

Terran::Terran() {
    SetName("");
    SetHealth(0);
}
// Creating new Terran
Terran::Terran(string name, int health) {
    SetName(name);
    SetHealth(health);
}

// randomly gets damage between 1-6 and returns the damage Terran and child classes
int Terran::Attack() {
   int damage = rand() % 6 +1;
   cout << GetName() << " attacks dealing " << damage << " damage." << endl;
    return damage;
}
// Prints out no special attack
int Terran::SpecialAttack() {
    cout << "Terran has no special attack" << endl;
    return 0;
}

