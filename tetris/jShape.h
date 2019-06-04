#ifndef ___JSHAPE___H__
#define ___JSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class JShape: public Shape{
  static const int numOrientations = 4;
  static Pos orientations[numOrientations][numBlocks];

 public:
  JShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
