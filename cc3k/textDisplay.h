#ifndef ___TEXT___D__H__
#define ___TEXT___D__H__

#include "display.h"
#include <vector>
#include <string>

class TextDisplay: public Display{
    std::vector<std::string> grid;
    int _height, _width;
  public:
    void updateDisplay(int x, int y, char c) override;
    void print(std::ostream&) override;
    TextDisplay(int height, int width);
};

#endif
