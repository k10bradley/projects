#include "lShape.h"
#include "cell.h"


Pos LShape::orientations[numOrientations][numBlocks] = {{{0,0},{0,1},{0,2},{1,2}},
                                                        {{0,0},{1,0},{2,0},{0,1}},
                                                        {{0,0},{1,0},{1,1},{1,2}},
                                                        {{2,0},{2,1},{1,1},{0,1}}};

LShape::LShape(Cell* start, Game& g):Shape(start->getNeighbour(Down), numOrientations, 'L', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* LShape::getOrientation(int ori) { return orientations[ori]; }
