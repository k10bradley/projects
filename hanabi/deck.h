#ifndef __DECK___H__
#define __DECK___H__

#include "card.h"
#include <vector>

class Deck{
  std::vector<Card> theDeck;
  void addSuit(Colour);
 public:
  Deck();
  int remaining();
  Card draw();
};
#endif
