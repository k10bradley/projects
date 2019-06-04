#ifndef __CARD__H__
#define __CARD__H__

#include <iostream>
#include <string>

enum Colour { blue = 0, green, red, white, yellow };
extern std::string colours[5];
//std::string colours[5];

class Card{
 private:
  Colour col;
  int value;
 public:
  Card(Colour col, int Val);
  friend std::ostream& operator<<(std::ostream& out, const Card& c);
  int getValue() const;
  Colour getColour() const;
};
#endif
