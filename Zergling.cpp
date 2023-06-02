#include "Zergling.h"

Zergling::Zergling() {
    SetName("");
    SetHealth(0);
}
//Creates new Zergling
Zergling::Zergling(string name, int health) {
    SetName(name);
    SetHealth(health);
}
// sets damage to 1 for special attack and returns the damage
int Zergling::SpecialAttack() {
    int damage = 1;
    cout << "scratches at you ferociously!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}