#include "Mutalisk.h"

Mutalisk::Mutalisk() {
    SetName("");
    SetHealth(0);
}
// Creates new Mutalisk
Mutalisk::Mutalisk(string name, int health) {
    SetName(name);
    SetHealth(health);
}
// sets damage to 4 for special attack and returns the damage
int Mutalisk::SpecialAttack() {
    int damage = 4;
    cout << "blasts you with their attack!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}