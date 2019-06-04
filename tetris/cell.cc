#include "cell.h"
#include "info.h"
#include "block.h"
#include <iostream>

Cell::Cell(int r, int c): row{r}, col{c} {
  for (int i = 0; i < 4; ++i ){
    neighbours[i] = nullptr;
  }
}

void Cell::setPos(int x, int y){
  row = x;
  col = y;
}
/*
void Cell::notify(Subject &){
}
*/

void Cell::remove(){
  if ( contents ) contents->remove();
  change(nullptr);
}

char Cell::getFill() const{
  if ( contents ) return contents->getColour();
  return ' '; 
}

void Cell::steal(Cell* oldLoc){
  if ( oldLoc->contents ) {
    change(oldLoc->contents);
    oldLoc->change(nullptr);
  } else {
    change(nullptr);
  }
}

Cell::~Cell(){
}

void Cell::change(Block* b){
  contents = b;
  notifyObservers();
};

Info Cell::getInfo() const{
  return {row, col, contents?contents->getColour():' '};
}

bool Cell::empty() const{ return contents == nullptr; }

void Cell::setNeighbour(Dir loc, Cell* c){
  neighbours[loc] = c;
}
  
  
bool Cell::canMove(Dir loc) const{
  if ( neighbours[loc] ){
    return neighbours[loc]->empty();
  }
  return false;
}

Cell* Cell::getNeighbour(Dir loc) const{
  return neighbours[loc];
}

Cell* Cell::getClose(int up, int right){
  if ( up > 0 ){
    return neighbours[Up]->getClose(up-1, right);
  }
  if ( up < 0 ){
    return neighbours[Down]->getClose(up+1, right);
  }
  if( right > 0 ){
    return neighbours[Right]->getClose(up, right-1);
  }
  if ( right < 0 ){
    return neighbours[Left]->getClose(up-1, right+1);
  }
  return this;
}
