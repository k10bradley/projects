#ifndef __CELL___H_
#define __CELL___H_

#include "subject.h"
#include "observer.h"
#include "info.h"
#include "dir.h"

class Block;


class Cell: public Subject{ //, public Observer{
  int row;
  int col;
  Block* contents = nullptr;

  void update();
  Cell* neighbours[4];

 public:
  Info getInfo() const override;
//  void notify(Subject &) override; 
  Cell(int r = 0, int c = 0);
  void setPos(int x, int y);

  void change(Block*);

  void steal(Cell*);

  char getFill() const;
  bool empty() const;
  void remove();

  void setNeighbour(Dir loc, Cell*);
  bool canMove(Dir) const;
  Cell* getNeighbour(Dir) const;

  Cell* getClose(int up, int right);

  ~Cell();
};

#endif
