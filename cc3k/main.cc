#include "textDisplay.h"
#include "manager.h"

#include <iostream>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  Manager man{h, w};

  man.play();
}
