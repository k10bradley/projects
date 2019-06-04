#ifndef ___TSHAPE___H__
#define ___TSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class TShape: public Shape{
  static const int numOrientations = 4;
  static Pos orientations[numOrientations][numBlocks];

 public:
  TShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
