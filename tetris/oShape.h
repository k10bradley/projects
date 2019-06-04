#ifndef ___OSHAPE___H__
#define ___OSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class OShape: public Shape{
  static const int numOrientations = 1;
  static Pos orientations[numOrientations][numBlocks];

  int orientation = 0;
 public:
  OShape(Cell* start, Game&);
  Pos* getOrientation(int ori);
};

#endif
