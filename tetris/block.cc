#include "block.h"
#include "cell.h"
#include "shape.h"
  
char Block::getColour() const{
  return colour;
}

void Block::setColour(char rep) { colour = rep; }

void Block::setLocation(Cell* c){ loc = c; }

void Block::detach(){
  if ( loc ) loc->change(nullptr);
}

Cell* Block::getLoc() { return loc; }

void Block::attach(){
  if ( loc ) loc->change(this);
}

void Block::remove(){
  loc = nullptr;
  owner->update();
}

void Block::setOwner(Shape* s){
  owner = s;
}

bool Block::check(Dir dir){
  return loc->canMove(dir);
}

void Block::shift(Dir dir){
  loc = loc->getNeighbour(dir);
}
