#include "list.h"
#include <iostream>

int main(){
  List<int> l;

  l.insertFront(10);
  l.insertFront(20);
  l.insertFront(30);

  for ( auto& elem: l ){
    std::cout << ++elem << std::endl;
  }
  for ( auto& elem: l ){
    std::cout << ++elem << std::endl;
  }

}
