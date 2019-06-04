#include "tShape.h"
#include "cell.h"


Pos TShape::orientations[numOrientations][numBlocks] = {{{0,0},{0,1},{0,2},{1,1}},
                                                        {{0,0},{1,0},{2,0},{1,1}},
                                                        {{0,1},{1,0},{1,1},{1,2}},
                                                        {{2,1},{1,1},{1,0},{0,1}}};

TShape::TShape(Cell* start, Game& g):Shape(start->getNeighbour(Down), numOrientations, 'T', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* TShape::getOrientation(int ori) { return orientations[ori]; }
