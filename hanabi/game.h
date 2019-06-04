#ifndef ___GAME__H____
#define ___GAME__H____

#include <vector>
#include "player.h"
#include "deck.h"

class GameOver{};

class Game{
  int piles[5] = {0,0,0,0,0};
  Deck deck;
  std::vector<Player> players;
 public:
  Game(int players = 4);
  void play();

  void takeTurn(int);
};

#endif
