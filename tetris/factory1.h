#ifndef __FACTORY_1_H_
#define __FACTORY_1_H_

#include "factory.h"

class Game;

class Factory1: public Factory{
  static const int ORDER_LENGTH = 7;
  static char order[ORDER_LENGTH];
  int next = 0;
 public:
  Factory1(Game &);
  Shape* getShape(Cell*) override;
};

#endif

