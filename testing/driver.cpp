#include <iostream>
#include <string>
#include "Board.h"
#include "Tile.h"

int main(void){
  //Board* test = new Board("   0   1   2   3\n  ----------------\nA |  ||  ||  ||  |\nB |  ||R5||  ||  |\nC |  ||R6||G6||  |\nD |  ||R4||  ||  |\nE |  ||  ||  ||  |");
  Board* test = new Board("   0   1   2  \n  ------------\nA |  ||  ||  |\nB |  ||O4||  |\nC |  ||  ||  |");
  std::cout << test->toString();
  //std::cout << test->placeTileAt(new Tile('B',6), "C3") << "\n";
  std::cout << test->toString();
  /*
  std::cout << test->placeTileAt(new Tile('R',5), "A1") << "\n";
  std::cout << test->toString();
  std::cout << test->placeTileAt(new Tile('G',6), "C2") << "\n";
  std::cout << test->toString();
  std::cout << test->placeTileAt(new Tile('R',4), "D1") << "\n";
  std::cout << test->toString();*/
  delete test;
  return 0;
}
