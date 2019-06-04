#ifndef ___CONTROLLER__H_
#define ___CONTROLLER__H_

#include <string>
#include "action.h"

class Controller{
 public:

  virtual Action takeTurn() = 0;
  virtual Action giveHint() = 0;
  virtual Action discardCard() = 0;
  virtual Action playCard() = 0;
  virtual ~Controller() = default;
};

#endif
