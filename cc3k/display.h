#ifndef ___DISPLAY__H___
#define ___DISPLAY__H___

#include <iostream>

class Display{

  public:
    virtual void updateDisplay(int x, int y, char c) = 0;
    virtual void print(std::ostream&) {};
    virtual ~Display() = default;
};


#endif
