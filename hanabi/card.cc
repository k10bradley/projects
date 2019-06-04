#include "card.h"

std::string colours[5] = {"Blue", "Green", "Red", "White", "Yellow"};

using namespace std;


Card::Card(Colour col, int val): col{col}, value{val} {
  if ( val > 5 || val < 1 ) throw val;
}

ostream& operator<<(std::ostream& out, const Card& c){
  out << colours[c.col] << " " << c.value;
  return out;
}

int Card::getValue() const { return value; }
Colour Card::getColour() const { return col; } 
