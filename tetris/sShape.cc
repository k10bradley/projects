#include "sShape.h"
#include "cell.h"


Pos SShape::orientations[numOrientations][numBlocks] = {{{0,0},{0,1},{1,1},{1,2}},
                                                        {{2,0},{1,0},{1,1},{0,1}}};

SShape::SShape(Cell* start, Game& g):Shape(start->getNeighbour(Down), numOrientations,'S', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* SShape::getOrientation(int ori) { return orientations[ori]; }
