#include "textDisplay.h"
#include "info.h"
#include "subject.h"
#include <iostream>

void TextDisplay::notify(Subject& s){
    Info i = s.getInfo();
    int col = i.col + 1;
    int row = i.row + 1 - 3;
    if ( row >= 1 ){
      grid[row][col] = i.colour;
    }
};

TextDisplay::TextDisplay(){
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < col; ++j){
       if ( j == col -1 ) grid[i][j] = '\0'; 
       else if ( i == 0 ) grid[i][j] = '_'; 
       else if ( j == 0 || j == col - 2 )grid[i][j] = '|'; 
       else if ( i == row - 1 )grid[i][j] = '_'; 
       else grid[i][j] = ' '; 
    }
  }
}

std::ostream& operator<<(std::ostream& out, const TextDisplay& td){
  for (int i = 0; i < td.row; ++i ){
    out << td.grid[i] << std::endl;
  }
  return out;
}
