
#include "VideoCharacter.h"

#include <iostream>
#include <string>

#define EXIT_SUCCESS    0
#define LENGTH          2

typedef VideoCharacter* VideoCharacterPtr;

void copyVCDeep(VideoCharacterPtr* src, VideoCharacterPtr* dest, int length);

int main(void) {
   VideoCharacterPtr* characters = new VideoCharacterPtr[LENGTH];

   std::string name = "Scalan";
   characters[0] = new VideoCharacter(name);

   name = "Grog";
   characters[1] = new VideoCharacter(name);

   std::cout << characters[0]->getName() << std::endl;
   std::cout << characters[1]->getName() << std::endl;

   // COPY!
   VideoCharacterPtr* duplicate = new VideoCharacterPtr[LENGTH];
   copyVCDeep(characters, duplicate, LENGTH);

   // TEST COPY!
   // TODO

   return EXIT_SUCCESS;
}

void copyVCDeep(VideoCharacterPtr* src, VideoCharacterPtr* dest, int length) {
   // TODO
}
