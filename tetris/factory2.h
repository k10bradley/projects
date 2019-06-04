#ifndef __FACTORY_2_H_
#define __FACTORY_2_H_

#include "factory.h"

class Game;

class Factory2: public Factory{
 public:
  Factory2(Game &);
  Shape* getShape(Cell*) override;
};

#endif

