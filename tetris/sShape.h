#ifndef ___SSHAPE___H__
#define ___SSHAPE___H__

#include "shape.h"

class Cell;
class Game;

class SShape: public Shape{
  static const int numOrientations = 2;
  static Pos orientations[numOrientations][numBlocks];

  int orientation = 0;
 public:
  SShape(Cell* start, Game&);

  Pos* getOrientation(int) override;
};

#endif
