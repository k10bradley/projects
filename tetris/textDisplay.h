#ifndef _TEXT____DISPLAY__
#define _TEXT____DISPLAY__

#include "display.h"
#include <iostream>
#include "observer.h"

class Subject;

class TextDisplay: public Observer{
  const int row = 22;
  const int col = 13;
  char grid[22][13];
 public:
  void notify(Subject&) override;

  TextDisplay();
  friend std::ostream& operator<<(std::ostream&, const TextDisplay&);
};
std::ostream& operator<<(std::ostream&, const TextDisplay&);

#endif
