#include "controller.h"
#include "command.h"

#include <iostream>
#include <string>

#include "exceptions.h"

using namespace std;

Controller::Controller(istream* in): in{in}{
  resetCommands();
}

void Controller::readCin(){
  in = &cin;
}

Command Controller::readCommand(){
  Command ret;
  int val;
  string action;
  if (*in >> val){
    ret.times = val;
  } else {
    val = 1;
  }
  if ( in->eof() ) throw GAMEOVER();
  in->clear();

  *in >> action;
  cerr << val << action << endl;
  ret.cmd = commands.find(action);
  return ret;
}

void Controller::addCommand(){
  string new_cmd;
  string old_cmd;
  *in >> new_cmd >> old_cmd;
  commands.insert(old_cmd, new_cmd);
}

void Controller::resetCommands(){
  commands.reset();
  commands.insert("I", I);
  commands.insert("J", J);
  commands.insert("L", L);
  commands.insert("O", O);
  commands.insert("S", S);
  commands.insert("T", T);
  commands.insert("Z", Z); 
//  commands.insert("up", UP);
  commands.insert("down", DOWN);
  commands.insert("right", RIGHT);
  commands.insert("left", LEFT);
  commands.insert("clockwise", CLOCK);
  commands.insert("counterclockwise", COUNTER);
  commands.insert("drop", DROP);
  commands.insert("levelup", LEVEL);
  commands.insert("command", COMMAND);
}
