#ifndef ___ZSHAPE___H__
#define ___ZSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class ZShape: public Shape{
  static const int numOrientations = 2;
  static Pos orientations[numOrientations][numBlocks];

  int orientation = 0;
 public:
  ZShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
