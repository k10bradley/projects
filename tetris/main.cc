#include "game.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
  int i = 1;
  std::istream* input = &std::cin;
  while ( i < argc ){
    string arg = argv[i];
    if ( arg == "-scriptfile"){
      if ( input != &cin ) delete input;
      input = new ifstream{argv[i+1]};
      ++i;
    }
    ++i;
  }
  Game g(input);
  std::cout << g;

  g.play();
  if ( input != &cin ) delete input;
}
