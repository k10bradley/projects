#include "iShape.h"
#include "cell.h"


Pos IShape::orientations[numOrientations][numBlocks] = {{{0,0},{0,1},{0,2},{0,3}},
                                                        {{0,0},{1,0},{2,0},{3,0}}};

IShape::IShape(Cell* start, Game& g):Shape(start, numOrientations, 'I', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* IShape::getOrientation(int ori) { return orientations[ori]; }
