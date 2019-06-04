#include "factory2.h"
#include "iShape.h"
#include "jShape.h"
#include "lShape.h"
#include "oShape.h"
#include "sShape.h"
#include "zShape.h"
#include "tShape.h"
#include "game.h"

Factory2::Factory2(Game& g): Factory{g} {}

const int dist = 12;

Shape* Factory2::getShape(Cell* c){
  int next = rand() % dist;
  if ( next < 2 ) return new IShape(c,theGame);
  if ( next < 4 ) return new JShape(c,theGame);
  if ( next < 6 ) return new LShape(c,theGame);
  if ( next < 8 ) return new OShape(c,theGame);
  if ( next < 10 ) return new TShape(c,theGame);
  if ( next < 11 ) return new SShape(c,theGame);
  if ( next < 12 ) return new ZShape(c,theGame);
  return nullptr;
}
