#include "VideoCharacter.h"

VideoCharacter::VideoCharacter(std::string& name) :
   name(name),
   leftHand(nullptr)
{}

VideoCharacter::VideoCharacter(VideoCharacter& other) :
    name(other.name),
    leftHand(new Weapon(*(other.leftHand)))
{}

VideoCharacter::~VideoCharacter() {
  deleteLeftHand();
}

std::string VideoCharacter::getName() {
   return name;
}

void VideoCharacter::setLeftHand(Weapon* w){
  deleteLeftHand();
  leftHand = w;
}
void VideoCharacter::deleteLeftHand(){
  if(leftHand != nullptr){
    delete leftHand;
  }
  leftHand = nullptr;
}
