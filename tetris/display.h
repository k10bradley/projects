#ifndef __DISPLAY__H___
#define __DISPLAY__H___

#include "observer.h"

// displays will observe all cells and update when a
// cell updates

class Display: public Observer{
  
 public:
  
};

// will have subclasses TextDisplay, GraphicDisplay, CurseDisplay

#endif
