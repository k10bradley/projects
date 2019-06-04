#ifndef ____BLOCK__H__
#define ____BLOCK__H__

#include "dir.h"

class Cell;
class Shape;

class Block{
  char colour = 'A';
  Cell* loc = nullptr;
  Shape* owner = nullptr;
  
 public:
  char getColour() const;

  Cell* getLoc();

  void setOwner(Shape*);
  void setLocation(Cell*);
  void setColour(char);

  void remove();
  void detach();
  void attach();
  bool check(Dir);
  void shift(Dir);
};

#endif
