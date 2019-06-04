#ifndef __OBSERVER__H___
#define __OBSERVER__H___

#include <vector>

class Subject;

class Observer{
  
 public:
  virtual void notify(Subject &) = 0; 

  virtual ~Observer() = default;
};

#endif
