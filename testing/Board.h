#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Tile.h"
#include <string>

class Board {
public:
   Board();
   Board(std::string savedBoard);
   ~Board();
   int placeTileAt(Tile* tile, std::string position);
   std::string toString();

private:
  int width = 1;
  int height = 1;
  Tile*** board = nullptr;
  bool firstTurn;
  bool matchConditions(Tile* tile, Tile* newTile, int* match);
  int getFarLeftTile(int x,int y);
  int getHighestUpTile(int x,int y);
  int validateLine(int x, int y, int axis, Tile* newTile);
  void insert(Tile* newTile, int x, int y);
};

#endif // ASSIGN2_BOARD_H
