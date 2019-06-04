#ifndef ___MANAGER__H__
#define ___MANAGER__H__

#include <vector>
#include "cell.h"

class Display;
//class Cell;


class Manager{
    Display* _display;
    std::vector<std::vector<Cell>> _grid;
    int x, y;
  public:
    Manager(int width, int height);

    void play();
};

#endif
