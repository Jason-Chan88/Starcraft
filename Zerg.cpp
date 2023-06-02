#include "Zerg.h"

Zerg::Zerg() {
    SetName("");
    SetHealth(0);
}
// Creates new Zerg
Zerg::Zerg(string name, int health) {
    SetName(name);
    SetHealth(health);
}
// sets the damage at 1 for regular attack and returns the damage
int Zerg::Attack() {
    int damage = 1;
    cout << GetName() << "deals " << damage << " point of damage!" << endl;
    return damage;
}

