#include "Weapon.h"

Weapon::Weapon(std::string& name) :
   name(name)
{}

Weapon::Weapon(Weapon& other) :
    name(other.name),
{}

Weapon::~Weapon() {
}

std::string Weapon::getName() {
   return name;
}
