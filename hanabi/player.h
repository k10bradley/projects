#ifndef __PLAYER___H_
#define __PLAYER___H_

#include <vector>
#include "card.h"
#include <iostream>
#include "controller.h"

class Action;
class Controller;

class Player{
  
  struct Known{
    bool value[5] = {true, true, true, true, true};
    bool colour[5] = {true, true, true, true, true};
  };

  int handSize;
  std::vector<Card> hand;
  std::vector<Known> knownInfo;

  Controller* control;

 public:
  Player(int handSize);
  int getHint(int value);
  int getHint(Colour colour);
  void drawCard(Card card);
  void printHand();

  Action takeTurn();

  friend std::ostream& operator<<(std::ostream&, const Player& p);
};

#endif
