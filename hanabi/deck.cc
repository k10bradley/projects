#include "deck.h"
#include <algorithm>

using namespace std;

void Deck::addSuit(Colour col){
  for (int j = 0; j < 3; ++j){
    theDeck.emplace_back(col, 1);
  }
  for ( int k = 2; k <= 4; ++k ){
    for (int j = 0; j < 2; ++j){
      theDeck.emplace_back(col, k);
    }
  }
  theDeck.emplace_back(col, 5);
}

Deck::Deck(){
  addSuit(Colour::blue);
  addSuit(Colour::green);
  addSuit(Colour::red);
  addSuit(Colour::white);
  addSuit(Colour::yellow);
  random_shuffle(theDeck.begin(), theDeck.end());
}

int Deck::remaining(){ return theDeck.size(); }

Card Deck::draw(){
  Card temp = theDeck.back();
  theDeck.pop_back();
  return temp;
}
