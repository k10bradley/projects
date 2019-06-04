#ifndef ___CELL_____H__
#define ___CELL_____H__

#include <vector>

class Display;

class Cell{
    int _x,_y;
    std::vector<Cell*> neighbours;
    Display* _d;
  public:
    Cell(int, int);
    void addNeighbour(Cell*, int);
    void addDisplay(Display*);
    Cell* getNeighbour(int dir);
    int getX();
    int getY();
};

#endif
