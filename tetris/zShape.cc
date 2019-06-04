#include "zShape.h"
#include "cell.h"


Pos ZShape::orientations[numOrientations][numBlocks] = {{{1,0},{1,1},{0,1},{0,2}},
                                                        {{0,0},{1,0},{1,1},{2,1}}};

ZShape::ZShape(Cell* start, Game& g):Shape(start->getNeighbour(Down), numOrientations, 'Z', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* ZShape::getOrientation(int ori) { return orientations[ori]; }
