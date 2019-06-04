#include "cell.h"

Cell::Cell(int x, int y): _x(x), _y(y), neighbours(8, nullptr){
}

void Cell::addNeighbour(Cell* c, int n){
  neighbours.at(n) = c;
}

void Cell::addDisplay(Display*d) { _d = d; }

Cell* Cell::getNeighbour(int dir){
  return neighbours.at(dir);
}

int Cell::getX() { return _x; }
int Cell::getY() { return _y; }
