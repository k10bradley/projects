#ifndef ___ISHAPE___H__
#define ___ISHAPE___H__

#include "shape.h"

class Cell;
class Game;

class IShape: public Shape{
  static const int numOrientations = 2;
  static Pos orientations[numOrientations][numBlocks];

  int orientation = 0;
 public:
  IShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
