#ifndef ___HUMAN__H_
#define ___HUMAN__H_

#include <string>
#include "controller.h"

class Human: public Controller{
  Action takeTurn() override;
  Action giveHint() override;
  Action discardCard() override;
  Action playCard() override;
};

#endif
