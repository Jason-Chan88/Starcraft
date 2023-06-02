#include "Ghost.h"

Ghost::Ghost() {
    SetName("");
    SetHealth(0);
}
//Creates new ghost
Ghost::Ghost(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Ghost::~Ghost() noexcept {

}
//randomly gets damage between 2-12 for special attack and returns the damage
int Ghost::SpecialAttack() {
    int damage = 2 + (rand() % 11);
    cout << "performs a sneak attack!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}