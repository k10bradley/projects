#ifndef ___SHAPE___H__
#define ___SHAPE___H__

#include "block.h"
#include <string>
#include "pos.h"
#include "dir.h"
#include "command.h"

class Game;
class Cell;
class Command;

const int numBlocks = 4;

class Shape{
  Block squares[numBlocks];
  int blocksRemaining = numBlocks;
  Cell* loc;

  int orientation = 0;
  int numOrientations;
  Pos** orientations;
  Game& theGame;

  void detach();
  
  bool shift(Dir);
  bool clock();
  bool counter();

  bool canMove(Cell**);

  void drop();

  Dir opToDir(Op op) const;

  virtual Pos* getOrientation(int) = 0;
 protected:
  void assignBlockLoc(int, Cell*);
  bool changeOrientation(Pos* locs);
  bool attach();
 public:

  int getOrientation();

  void update();
  
  Shape(Cell* start, int numOrientations, char rep, Game& game);

  void move(Command& command);

  void remove();
  
  virtual ~Shape() = default;
};

#endif
