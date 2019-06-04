#ifndef ___COMMANDS__H__
#define ___COMMANDS__H__

enum Op {NONE = 0, LEVEL, UP, RIGHT, DOWN, LEFT, CLOCK, COUNTER, DROP, I, J, L, O, S, T, Z, COMMAND};

struct Command{
  int times = 1;
  Op cmd;
};

#endif
