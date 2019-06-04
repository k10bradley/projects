#include "oShape.h"
#include "cell.h"

Pos OShape::orientations[1][4] = {{{0,0},{0,1},{1,0},{1,1}}};

OShape::OShape(Cell* start, Game& g): Shape{start, 1, 'O', g} {
  changeOrientation(getOrientation(0));   
  attach();
}

Pos* OShape::getOrientation(int ori) { return orientations[ori]; }
