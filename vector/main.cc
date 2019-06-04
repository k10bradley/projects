#include "vector.h"
#include <iostream>
#include <string>

int main(){
  Vector<std::string> vec;

  std::string temp;
  while( std::cin >> temp){
    vec.push_back(temp);
  }
  
  for( std::string& elem: vec ){
    std::cout << elem << std::endl;
  }
}
