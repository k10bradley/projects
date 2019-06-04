#ifndef ___LSHAPE___H__
#define ___LSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class LShape: public Shape{
  static const int numOrientations = 4;
  static Pos orientations[numOrientations][numBlocks];

 public:
  LShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
