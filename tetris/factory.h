#ifndef __FACTORY__H__
#define __FACTORY__H__

class Shape;
class Cell;
class Game;

class Factory{
 protected:
  Game& theGame;
 public:
  Factory(Game& g);
  virtual ~Factory() = default;
  virtual Shape* getShape(Cell*) = 0;

};
#endif
