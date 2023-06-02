#include "Battlecruiser.h"

Battlecruiser::Battlecruiser() {
    SetName("");
    SetHealth(0);
}
//Creates new Battlecruiser
Battlecruiser::Battlecruiser(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Battlecruiser::~Battlecruiser() {

}
//randomly gets damage between 3-12 for special attack and returns the damage
int Battlecruiser::SpecialAttack() {
    int damage = 3 + (rand() % 10);
    cout << "uses the Yomato Cannon!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}
