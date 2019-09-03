
#ifndef VIDEO_CHARACTER_H
#define VIDEO_CHARACTER_H

#include <string>
#include "Weapon.h"

class VideoCharacter {
public:
   VideoCharacter(std::string& name);
   VideoCharacter(VideoCharacter& other);
   ~VideoCharacter();

   std::string getName();
   void setLeftHand(Weapon& w);
   void disarmLeftHand();

private:
   std::string name;
};

#endif // VIDEO_CHARACTER_H
