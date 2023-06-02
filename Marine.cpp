#include "Marine.h"

Marine::Marine() {
    SetName("");
    SetHealth(0);
}
// Creating new marine
Marine::Marine(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Marine::~Marine() noexcept {

}
//randomly gets damage between 1-8 for special attack and returns the damage
int Marine::SpecialAttack() {
    int damage = rand() % 8 +1;
    cout << "spins up doing GATLING DAMAGE!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}