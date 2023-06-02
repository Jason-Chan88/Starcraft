#include "Entity.h"
// Default Constructor
Entity::Entity() {
    m_name = "";
    m_health = 0;
}
// Overload Constructor
Entity::Entity(string name, int health) {
    SetName(name);
    SetHealth(health);
}
// Destructor
Entity::~Entity() {

}
// Setters and Getters for Entity and all the child classes
string Entity::GetName() {
    return m_name;
}

int Entity::GetHealth() {
    return m_health;
}

void Entity::SetName(string name) {
    m_name = name;
}

void Entity::SetHealth(int health) {
    m_health = health;
}

ostream& operator<<(ostream& output, Entity& a) {
    output << a.GetName() << "'s health:" << a.GetHealth();
    return output;
}



