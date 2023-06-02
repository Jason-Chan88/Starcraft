#include "Hydralisk.h"

Hydralisk::Hydralisk() {
    SetName("");
    SetHealth(0);
}
// Creates new Hydralisk
Hydralisk::Hydralisk(string name, int health) {
    SetName(name);
    SetHealth(health);
}
// sets damage to 2 for special attack and returns the damage
int Hydralisk::SpecialAttack() {
    int damage = 2;
    cout << "sprays you with deadly acid!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}