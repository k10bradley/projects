#include "game.h"
#include <vector>
#include <ctime>
#include <cstdlib>

int main(){
  srand(time(NULL));

  Game g;

  g.play();
}
