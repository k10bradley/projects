
#include "textDisplay.h"


void TextDisplay::updateDisplay(int x, int y, char c){
  grid.at(y).at(x) = c;
}

TextDisplay::TextDisplay(int height, int width): _height(height), _width(width){
  std::string line;
  for(int i = 0; i < width; ++i){
    line += ' ';
  }
  for(int i = 0; i < height; ++i){
    grid.push_back(line);
  }
}

void TextDisplay::print(std::ostream& out){
  for(int i = 0; i < _width + 2; ++i ) {
    out << '-';
  }
  out << std::endl;
  for( auto line: grid ) out << '|' << line << '|' << std::endl;
  for(int i = 0; i < _width + 2; ++i ) {
    out << '-';
  }
  out << std::endl;
}
