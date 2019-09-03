
#include <string>
#include <iostream>

typedef float HP;

using std::string;

class Character {

public:
  Character(string name, HP maxHealth);

  ~Character();

  HP damage(HP damage);

  HP heal(HP healPoints);

  void addToInv(string item);

  int getNumItems();

  string getItem(int i);

  void toConsole();

private:
  string inventory[10];
  int numItems;
  HP hitPoints;
  HP maxHealth;
  string name;
};
