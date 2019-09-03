
#include "Board.h"
#include <iostream>

#define INVALID   -1
#define QWIRKLE   6
#define H         0
#define V         1

Board::Board() {
  firstTurn = true;
  board = new Tile **[height];
  for(int i = 0; i < height;i++){
    board[i] = new Tile*[width];
  }
}
Board::Board(std::string savedBoard) {
  //load from save string
  width = 0;
  height = -1;
  bool tile = false;
  int length = savedBoard.length();
  for(int i = 0; i < length;i++){
     if(savedBoard[i] == '|' && height < 2){
      tile = !tile;
      if(tile == false){
        width++;
      }
    }
    else if (savedBoard[i] == '\n'){
      height++;
      if(height < 1){
        width = 0;
      }
    }
  }

  board = new Tile **[height];
  for(int i = 0; i < height;i++){
    board[i] = new Tile*[width];
  }

  tile = false;
  int x = 0;
  int y = -2;
  int count = 0;
  char colour = 'A';
  for(int i = 0; i < length;i++){
    if(tile == true && savedBoard[i] != '|'){
      if(savedBoard[i] != ' '){
        count++;
      }
      if(count == 1){
        colour = savedBoard[i];
      }
      else if(count == 2){
        board[y][x] = new Tile (colour, savedBoard[i] - '0');
        firstTurn = true;
        count = 0;
      }
    }
    else if(savedBoard[i] == '|'){
      tile = !tile;
      if(tile == false){
        x++;
      }
    }
    else if (savedBoard[i] == '\n'){
      y++;
      x = 0;
    }
  }
}

Board::~Board() {
  for(int j = 0; j < height;j++){
    for(int i = 0; i < width;i++){
      delete board[j][i];
    }
    delete[] board[j];
  }
  delete[] board;
}

int Board::placeTileAt(Tile* newTile, std::string position){
  int y = position[0] - (int) 'A';
  int x = stoi(position.substr(1,position.npos));
  int score = 0;
  // firstTurn add tile to specified position
  // when board is resizable first tile will always be at [1][1]
  if(firstTurn){
    insert(newTile,x,y);
    firstTurn = false;
    score = 1;
  }
  else{
    //stops grid from getting any bigger.
    if(width == 26 && (x == 0 || x == 26)){
      score = INVALID;
    }
    else if(height == 26 && (y == 0 || y == 26)){
      score = INVALID;
    }
    //
    else if(x > width - 1 || y > height - 1 || y < 0 || x < 0){
      score = INVALID;
    }
    //can only place piece on empty square
    else if(board[y][x] == nullptr)
    {
      //check horizontal array can fit new tile
      int length1 = validateLine(x,y,H, newTile);
      int length2 = validateLine(x,y,V, newTile);
      //tried to place a tile by itself - {originally a long if statement}
      if(length1 < 2 && length2 < 2){
        length1 = INVALID;
        length2 = INVALID;
      }
      //calculate score
      if(length1 != INVALID && length2 != INVALID){
        score = length1 + length2;
        if(length1 == QWIRKLE){
          score += QWIRKLE;
        }
        if(length2 == QWIRKLE){
          score += QWIRKLE;
        }
      }
      else{
        score = INVALID;
      }
      //if score is Invalid dont place a piece
      if(score != INVALID){
        //place tile
        insert(newTile,x,y);
      }
    }
    else{
      score = INVALID;
    }
  }
  return score;
}

int Board::getFarLeftTile(int x,int y){
  int i = 0;
  while(x + i - 1 > -1 && board[y][x + i - 1] != nullptr){
    --i;
  }

  return i;
}

int Board::getHighestUpTile(int x,int y){
  int i = 0;
  while(y + i - 1 > -1 && board[y + i - 1][x] != nullptr){
    --i;
  }
  return i;
}

/* validateLine()
 * This function is used to validate two important factors of a Line, its length and its matchCondition
 * the method begins by searching for the LEFT/UP-most tile from the x,y given
 * then to the RIGHT/DOWN-most tile while keeping count of the length of the line.
 * As the line is iterated over a matchCondition must be found,
 * if none are found or one is violated, validateLine is will return an invalid length value.
 */
int Board::validateLine(int x, int y, int axis, Tile* newTile){
  int i = 0;
  int j = 0;
  if(axis == H){
    i = getFarLeftTile(x,y);
  }
  else if(axis == V){
    j = getHighestUpTile(x,y);
  }
  int length = 0;
  int* match = new int(INVALID);
  while(y + j < height && x + i < width && (board[y + j][x + i] != nullptr || (y + j == y && x + i == x))){
    if(y + j != y || x + i != x){
      if(length == INVALID || !matchConditions(board[y+j][x+i], newTile, match)){
        length = INVALID;
      }
    }
    if(axis == H){
      ++i;
    }
    else if(axis == V){
      ++j;
    }

    if(length != INVALID){
      ++length;
    }
  }
  if(length == 1){
    length = 0;
  }
  delete match;
  return length;
}
/* matchConditions()
 * if the new tile matches a tile return false
 * if no matchCondition has been specified yet, find a matchCondition, if a matchCondition can't be found return false
 * if a matchCondition is already specified, but this tile does not match it return false
 * else return true.
 */
bool Board::matchConditions(Tile* tile, Tile* newTile, int* match){
  bool isValid = true;
  if(tile->colourMatch(newTile->getColour()) && tile->shapeMatch(newTile->getShape())){
    isValid = false;
  }
  else if(*match == INVALID ){
    if(tile->colourMatch(newTile->getColour())){
      *match = newTile->getColour();
    }
    else if(tile->shapeMatch(newTile->getShape())){
      *match = newTile->getShape();
    }
    else {
      isValid = false;
    }
  }
  else{
    if(! (tile->colourMatch(*match) || tile->shapeMatch(*match) ) ){
      isValid = false;
    }
  }
  return isValid;
}
void Board::insert(Tile* newTile, int x, int y){
  //if x == width - 1: push nullptr to board[width][y]
  //if x == 0: push null ptr to board[0][y]
  //if y = height - 1: push nullptr to board[x][height]
  //if y == 0: push nullptr to board[x][0]
  Tile*** tempBoard = nullptr;
  int xOffset = 0;
  int yOffset = 0;
  int widthOffset = 0;
  int heightOffset = 0;
  if(x == width - 1){
    widthOffset++;
  }
  if(x == 0){
    widthOffset++;
    xOffset = 1;
  }
  if(y == height - 1){
    heightOffset++;
  }
  if(y == 0){
    heightOffset++;
    yOffset = 1;
  }
  if(heightOffset > 0 || widthOffset > 0){
    tempBoard = board;
    //set aside new place in memory
    board = new Tile **[height + heightOffset];
    for(int i = 0;i < height + heightOffset;i++){
      board[i] = new Tile*[width + widthOffset];
      for(int j = 0;j < width + widthOffset;j++){
        board[i][j] = nullptr;
      }
    }

    for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
        board[i+yOffset][j+xOffset] = tempBoard[i][j];
      }
    }
    //delete tempBoard from memory;
    //careful not to delete the Tile* as board needs them.
    for(int j = 0; j < height;j++){
      delete[] tempBoard[j];
    }
    delete[] tempBoard;

    width = width + widthOffset;
    height = height + heightOffset;
  }
  board[y+yOffset][x+xOffset] = newTile;
}

std::string Board::toString(){
  std::string boardString = "  ";
  for(int i = 0;i < width;i++){
    boardString += " ";
    boardString += std::to_string(i);
    if(i < 10){
      boardString += " ";
    }
    boardString += " ";
  }
  boardString +="\n  ";
  for(int i = 0;i < width;i++){
    boardString += "----";
  }
  boardString +="\n";
  for(int i = 0;i < height;i++){
    char side = 'A' + i;
    boardString += side;
    boardString += " ";
    for(int j = 0;j < width;j++){
      if(board[i][j] != nullptr)
        boardString += "|" + board[i][j]->toString() + "|";
      else
        boardString += "|  |";
    }
    boardString += "\n";
  }
  return boardString;
}
