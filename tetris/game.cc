#include "game.h"
#include "cell.h"
#include "textDisplay.h"
#include <iostream>
#include "factory1.h"
#include "factory2.h"
#include "shape.h"
#include <sstream>
#include "command.h"
#include "controller.h"
#include "dir.h"

#include "exceptions.h"

using namespace std;


Game::Game(istream* in): count{0}, controller(new Controller(in)),testFactory(*this) {

  // create cells
  for(int i = 0; i < height; ++i){
    vector<Cell> newRow;
    for (int j = 0; j < width; ++j){
      Cell c{i,j};
      newRow.emplace_back(c);
    }
    theGrid.emplace_back(newRow);
  }
  display = new TextDisplay();

  // assign neighbours
  for(int i = 0; i < height; ++i){
    for(int j = 0; j < width; ++j){
      theGrid[i][j].attach(display);
      if ( i != 0 ) theGrid[i][j].setNeighbour(Up, &theGrid[i-1][j]);
      if ( i != height-1 ) theGrid[i][j].setNeighbour(Down, &theGrid[i+1][j]);
      if ( j != 0 ) theGrid[i][j].setNeighbour(Left, &theGrid[i][j-1]);
      if ( j != width-1 ) theGrid[i][j].setNeighbour(Right, &theGrid[i][j+1]);
    }
  }
  factory = new Factory1(*this);
  cur = factory->getShape( &theGrid[3][0] );

  if ( in != &cin ){
    try {
      while (true) handleMove();
    } catch (GAMEOVER& go){
      controller->readCin();
    }
  }
}


void Game::move(Command& command){
  cur->move(command);
}


void Game::play(){
  string s;
  try {
    while( true ) handleMove();
  } catch ( GAMEOVER& go ){
    cout << "GAME OVER" << endl;
  }
}

void Game::handleMove(){
  Command action = controller->readCommand();

  switch (action.cmd)
  {
    case NONE:
      cout << "Invalid command" << endl;
      break;
    case LEVEL:
      {
        delete factory;
        factory = new Factory2(*this);
        break;
      }
    case UP:
    case DOWN:
    case RIGHT:
    case LEFT:
    case CLOCK:
    case COUNTER:
    case DROP:
      {
        move(action);
        int num = action.times;
        if( action.cmd == DROP ){
          while ( true ){
            updateRows();
            shapes.push_front(cur);
            cur = factory->getShape( &theGrid[3][0] );
            --num;
            if ( num == 0 ) break;
            move(action);
          }
        }
        break;
      }
    case I:
    case J:
    case L:
    case O:
    case S:
    case T:
    case Z:
      {
        // change to type of block input 
        cur->remove();
        delete cur;
        cur = testFactory.getShape( &theGrid[3][0], action.cmd );
      }
    case COMMAND:
      {
        controller->addCommand();
      }
  }
  cout << *this;
}


int Game::moveType(string& move){
  int n = 0;
  string rest;
  istringstream ss{move};
  ss >> n;
  ss.clear();
  ss >> rest;

  if ( rest == "right" || rest == "left" || rest == "up" || rest == "down" || rest == "c" || rest == "cc" || rest == "drop" ){
    return RIGHT;
  }
  return NONE;
}

string Game::fullWord(string& s){
  int n = 1;
  string rest;
  istringstream ss{s};
  ss >> n;
  if ( ss.fail() ){
    ss.clear();
    n = 1;
  }
  ss >> rest;

  if ( rest == "r" || rest == "ri" || rest == "rig" || rest == "righ" || rest == "right" ){
    rest = "right";
  } else if ( rest == "l" || rest == "le" || rest == "lef" || rest == "left"){
    rest = "left";
  } else if ( rest == "u" || rest == "up" ){
    rest = "up";  
  } else if ( rest == "do" || rest == "dow" || rest == "down" ){
    rest = "down";
  } else if ( rest == "dr" || rest == "dro" || rest == "drop" ){
    rest = "drop";
  }


  ostringstream out;
  out << n << rest;
  return out.str();
}

void Game::updateRows(){
  vector<int> removed;
  for (int i = height - 1; i >= 0; --i){
    count[i] = 0;
    for(int j = 0; j < width; ++j){
      if ( ! theGrid[i][j].empty() ) ++count[i];
    }
    if ( count[i] == width ){
      removeRow(i);
      removed.emplace_back(i);
    }
  }
  auto it = removed.begin();
  int moveRows = 0;
  if ( it != removed.end() ){
    for (int i = height -1; i >= 0 ; --i){
      if ( count[i] == 0 ) continue;
      if ( it != removed.end() && i == *it ){
        ++moveRows;
        ++it;
      } else if ( moveRows > 0 ){
        for( int j = 0; j < width; ++j){
          theGrid[i+moveRows][j].steal(&theGrid[i][j]);
        }
      }
    }
  }
  int val = moveRows + 1;
  if ( val > 1 ) score += val * val;
}

void Game::removeRow(int removing){
  for(auto cell: theGrid[removing])
    cell.remove();  
}

std::ostream& operator<<(std::ostream& out, Game& g){

  return out << "Score: " << g.score << endl << *g.display;
}

void Game::remove(Shape * s){
    score += 10;
    return;
}

Game::~Game(){
  for ( auto shape: shapes ){
    delete shape;
  }
  delete display;
  delete factory;
  delete cur;
}
