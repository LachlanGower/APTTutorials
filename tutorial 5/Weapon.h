
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
   Weapon(std::string& name);
   Weapon(Weapon& other);
   ~Weapon();

   std::string getName();

private:
   std::string name;
};

#endif // WEAPON_H
