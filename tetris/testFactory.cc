#include "testFactory.h"
#include "iShape.h"
#include "jShape.h"
#include "lShape.h"
#include "oShape.h"
#include "sShape.h"
#include "zShape.h"
#include "tShape.h"
#include "game.h"
#include "command.h"

TestFactory::TestFactory(Game& g): theGame(g) {}

Shape* TestFactory::getShape(Cell* c, Op which){
  switch(which){
    case I:
      return new IShape(c,theGame);
    case J:
      return new JShape(c,theGame);
    case L:
      return new LShape(c,theGame);
    case O:
      return new OShape(c,theGame);
    case S:
      return new SShape(c,theGame);
    case T:
      return new TShape(c,theGame);
    case Z:
      return new ZShape(c,theGame);
    default:
      return nullptr;
  }
}
