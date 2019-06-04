#ifndef ___CONTROLLER___H__
#define ___CONTROLLER___H__
#include "trie.h"
#include <iostream>

class Command;

class Controller{
  Trie commands;
  std::istream* in;
 public:
  Command readCommand();
  void readCin();
  Controller(std::istream* in = &std::cin);
  void resetCommands();

  void addCommand();
};

#endif
