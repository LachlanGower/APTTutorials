#include "Character.h"

int main(void){
  Character alex = Character("Alex", 50);
  alex.damage(20);
  alex.addToInv("what is love?");
  alex.addToInv("baby don't hurt me");
  alex.toConsole();

  Character* harry = new Character("Harry", 40);
  harry->heal(20);
  harry->addToInv("don't hurt me");
  harry->addToInv("don't hurt me");
  harry->addToInv("don't hurt me");
  harry->addToInv("don't hurt me");
  harry->addToInv("don't hurt me");
  harry->addToInv("don't hurt me");
  harry->addToInv("no more");
  harry->toConsole();
  delete(harry);
}

Character::Character(std::string name, HP maxHealth){
  this->name = name;
  this->hitPoints = maxHealth;
  this->numItems = 0;
  //this->inventory = new string[10];
}
Character::~Character(){
}
HP Character::damage(HP damage){
  hitPoints -= damage;
  if(hitPoints < 0){hitPoints = 0;}
  return hitPoints;
}
HP Character::heal(HP healPoints){
  hitPoints += healPoints;
  return hitPoints;
}
void Character::addToInv(string item){
  if(numItems < 9){
    inventory[numItems] = item;
    numItems+=1;

  }
}

int Character::getNumItems(){
  return numItems;
}

string Character::getItem(int i){
  return inventory[i];
}

void Character::toConsole(){
  std::cout << "Character: " << name << " Health: " <<  hitPoints << "\n";
  std::cout << "Inventory:\n";
  for(int i = 0; i < getNumItems();i++){
    std::cout << "\tItem "<< i + 1 << ": " << getItem(i) << "\n";
  }
}
