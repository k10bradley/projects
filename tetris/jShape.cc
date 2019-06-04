#include "jShape.h"
#include "cell.h"
#include "dir.h"

Pos JShape::orientations[numOrientations][numBlocks] = {{{0,0},{0,1},{0,2},{1,0}},
                                                        {{0,0},{1,0},{2,0},{2,1}},
                                                        {{1,0},{1,1},{1,2},{0,2}},
                                                        {{0,0},{0,1},{1,1},{2,1}}};

JShape::JShape(Cell* start, Game& g):Shape(start->getNeighbour(Down), numOrientations, 'J', g) {
  changeOrientation(getOrientation(0));  
  attach();
}

Pos* JShape::getOrientation(int ori) { return orientations[ori]; }
