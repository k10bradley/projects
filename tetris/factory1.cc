#include "factory1.h"
#include "iShape.h"
#include "jShape.h"
#include "lShape.h"
#include "oShape.h"
#include "sShape.h"
#include "zShape.h"
#include "tShape.h"
#include "game.h"

Factory1::Factory1(Game& g): Factory{g} {}

char Factory1::order[Factory1::ORDER_LENGTH] = {'I','J','L','O','S','Z','T'};

Shape* Factory1::getShape(Cell* c){
  char type = order[next];
  next = (next + 1)% ORDER_LENGTH;
  if ( type == 'I' ) return new IShape(c,theGame);
  if ( type == 'J' ) return new JShape(c,theGame);
  if ( type == 'L' ) return new LShape(c,theGame);
  if ( type == 'O' ) return new OShape(c,theGame);
  if ( type == 'S' ) return new SShape(c,theGame);
  if ( type == 'Z' ) return new ZShape(c,theGame);
  if ( type == 'T' ) return new TShape(c,theGame);
  return nullptr;
}
