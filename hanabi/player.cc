#include "player.h"
#include "controller.h"
#include "human.h"

using namespace std;

Player::Player(int handSize): handSize{handSize}, control{new Human} {}

int Player::getHint(int value){
  int res = 0;
  for (unsigned int i = 0; i < hand.size(); ++i){
    if ( hand[i].getValue() == value ) ++res;
  }
  if ( res == 0 ) return res;
  for (unsigned int i = 0; i < hand.size(); ++i){
      // does card i match the value?
      if ( hand[i].getValue() == value ){
        // if so, it is not the other values
        for ( unsigned int j = 0; j < 5; ++j ){
          if ( j != value - 1 ) {
            knownInfo[i].value[j] = false;
          }
        }
      } else {
        // if not, mark it
        knownInfo[i].value[value-1] = false;
      }
  }
  return res;
}

int Player::getHint(Colour colour){
  int res = 0;
  for (unsigned int i = 0; i < hand.size(); ++i){
    if ( hand[i].getColour() == colour ) ++res;
  }
  if ( res == 0 ) return res;
  for (unsigned int i = 0; i < hand.size(); ++i){
      if ( hand[i].getColour() == colour ){
        for ( unsigned int j = 0; j < 5; ++j ){
          if ( j != colour ) {
            knownInfo[i].colour[j] = false;
          }
        }
      } else {
        knownInfo[i].value[colour] = false;
      }
  }
  for (unsigned int i = 0; i < hand.size(); ++i){
    knownInfo[i].colour[colour] = hand[i].getColour() == colour;
  }
  return res;
}

void Player::drawCard(Card card){
  hand.emplace_back(card);
  knownInfo.emplace_back();
}

ostream& operator<<(ostream& out, const Player& p){
  for ( auto info: p.knownInfo ){
    out << "Possible:";
    for ( int i = 0; i < 5; ++i ){
      if ( info.value[i] ){
        out << " " << i + 1;
      }
    }
    for ( int i = 0; i < 5; ++i ){
      if ( info.colour[i] ){
        out << " " << colours[i];
      }
    }
  out << endl;
  }
  return out;
}

void Player::printHand(){
  bool first = true;
  for ( auto card: hand ){
    if ( first ) {
      first = false;
    } else {
      cout << ", ";
    }
    cout << card;
  }
}

Action Player::takeTurn(){
  return control->takeTurn();
}
