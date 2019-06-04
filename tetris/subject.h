#ifndef ___SUBJECT__H__
#define ___SUBJECT__H__

#include <vector>

class Observer;
class Info;

class Subject{
  std::vector<Observer*> observers;
 public:
  
  void attach(Observer *o);
  void notifyObservers();  // potentially use subscription Type
  virtual Info getInfo() const= 0;

  virtual ~Subject() = default;
};

#endif
