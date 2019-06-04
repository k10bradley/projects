#ifndef ___TEST___FACTORY__H__
#define ___TEST___FACTORY__H__

#include "command.h"

class Shape;
class Cell;
class Game;

class TestFactory{
 protected:
  Game& theGame;
 public:
  TestFactory(Game& g);
  virtual ~TestFactory() = default;
  virtual Shape* getShape(Cell*, Op);
};

#endif
