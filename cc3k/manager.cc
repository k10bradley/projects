#include "display.h"
#include "cell.h"
#include "manager.h"
#include "textDisplay.h"
#include <string>
#include <iostream>

using namespace std;

Manager::Manager(int width, int height): _display{new TextDisplay{width,height}}, x{0}, y{0} {
  for( int i = 0; i < height; ++i ){
    vector<Cell> row;
    for( int j = 0; j < width; ++j ){
      Cell c{i, j};
      row.emplace_back(c);
    }
    _grid.emplace_back(row);
  }
  for ( int i = 0; i < height; ++i ){
    for ( int j = 0; j < width; ++j ){
      Cell* cur = &_grid.at(i).at(j);
      if ( i > 0 ) cur->addNeighbour(&_grid.at(i-1).at(j), 0); // N
      if ( i > 0 && j < width - 1 ) cur->addNeighbour(&_grid.at(i-1).at(j+1), 1); // NE
      if ( j < width - 1 ) cur->addNeighbour(&_grid.at(i).at(j + 1), 2); // E
      if ( i < height - 1 && j < width - 1 ) cur->addNeighbour(&_grid.at(i+1).at(j+1), 3); // SE
      if ( i < height - 1 ) cur->addNeighbour(&_grid.at(i+1).at(j), 4); // S
      if ( i < height - 1 && j > 0 ) cur->addNeighbour(&_grid.at(i+1).at(j-1), 5); // SW
      if ( j > 0 ) cur->addNeighbour(&_grid.at(i).at(j-1), 6); // W
      if ( i > 0 && j > 0 ) cur->addNeighbour(&_grid.at(i-1).at(j-1), 7); // NW
    }
  } 
  _display->updateDisplay(y, x, '*');
  _display->print(cout);
}

void Manager::play(){
  std::string move;
  int dir;
  while ( cin >> move ){
    dir = -1;
    if ( move == "N" ) dir = 0;
    else if ( move == "NE" ) dir = 1;
    else if ( move == "E" ) dir = 2;
    else if ( move == "SE" ) dir = 3;
    else if ( move == "S" ) dir = 4;
    else if ( move == "SW" ) dir = 5;
    else if ( move == "W" ) dir = 6;
    else if ( move == "NW" ) dir = 7;
    
    if ( dir != -1 ){
      _display->updateDisplay(y, x, ' ');
      Cell* temp = _grid.at(x).at(y).getNeighbour(dir);
      if ( temp ){
        x = temp->getX();
        y = temp->getY();
        _display->updateDisplay(y, x, '*');
        _display->print(cout);
      } else {
        cout << "You hit a wall. Ouch." << endl;
      } 
    }

  }
}
