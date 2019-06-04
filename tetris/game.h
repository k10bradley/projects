#ifndef ___GAME___
#define ___GAME___
#include <vector>
#include <iostream>
#include "cell.h"
#include "textDisplay.h"
#include <list>
#include <memory>
#include "testFactory.h"

class Shape;
class Factory;
class Controller;
class Command;

class Game{
  int height = 23;
  int width = 10;
  std::list<Shape*> shapes;
  std::vector<std::vector<Cell>> theGrid;
  int count[23];

  Controller* controller;

  TextDisplay* display;

  TestFactory testFactory;
  Factory* factory;
  Shape* cur;

  int score = 0;

  void updateRows();
  void removeRow(int);

  int moveType(std::string&);
  std::string fullWord(std::string&);
  
  void move(Command& command);

 public:
  Game(std::istream* in = &std::cin);

  void print();

  void play();

  void remove(Shape *);

  void handleMove();

  ~Game();

  friend std::ostream& operator<<(std::ostream&, Game&);
};

std::ostream& operator<<(std::ostream&, Game&);


#endif
