#include "shape.h"
#include <string>
#include "cell.h"
#include <sstream>
#include "game.h"
#include <map>
#include "command.h"

using namespace std;


Shape::Shape(Cell* start, int numOri, char c, Game& theGame): loc(start), numOrientations(numOri),
  theGame(theGame) {
  for(int i = 0; i < numBlocks; ++i){
    squares[i].setColour(c);
    squares[i].setOwner(this);
  }
}

bool Shape::canMove(Cell** locs){
  for(int i = 0; i < numBlocks; ++i){
    if ( !locs[i] ) return false;
    if (!locs[i]->empty()) return false;
  }
  return true;
}

bool Shape::changeOrientation(Pos* locs){
  Cell* newLocs[4];

  for(int i = 0; i < numBlocks; ++i){
    newLocs[i] = loc->getClose(locs[i].x, locs[i].y);
  }

  if ( canMove(newLocs) ){
    for( int i = 0; i < numBlocks; ++i){
      squares[i].setLocation(newLocs[i]);
    }
    attach();
    return true;
  }
  return false;
}


void Shape::detach(){
  for (int i = 0; i < numBlocks; ++i ){
    squares[i].detach();
  }
}

bool Shape::attach(){
  for (int i = 0; i < numBlocks; ++i ){
    squares[i].attach();
  }
  return true;
}

void Shape::assignBlockLoc(int b, Cell* c){
  squares[b].setLocation(c);
}

void Shape::drop(){
  while ( shift(Down) );
}

Dir Shape::opToDir(Op op) const{
  if ( op == UP ) return Up;
  if ( op == RIGHT ) return Right;
  if ( op == DOWN ) return Down;
  if ( op == LEFT ) return Left;
  return Up;
}

void Shape::move(Command& command){
  detach();

  int repeat = command.times;
  Op action = command.cmd;
  
  Dir direction = opToDir(action);

  switch ( action ){
    case UP:
    case DOWN:
    case RIGHT:
    case LEFT:
      while ( repeat > 0 ){
        --repeat;
        shift(direction);
      }
      break;

    case DROP:
      --repeat;
      drop();
      break;

    case CLOCK:
      while ( repeat > 0 ){
        --repeat;
        clock();
      }
      break;

    case COUNTER:
      while ( repeat > 0 ){
        --repeat;
        counter();
      }
      break;
    default:
      break;
  }
  attach();
}
  
int Shape::getOrientation(){
  return orientation;
}

bool Shape::clock(){
  orientation = (orientation + 1)%numOrientations;
  return changeOrientation(getOrientation(orientation));
}

bool Shape::counter(){
  orientation = (orientation + 3)%numOrientations;
  return changeOrientation(getOrientation(orientation));
}

void Shape::update(){
  --blocksRemaining;
  if ( blocksRemaining == 0 ){
    theGame.remove(this);
  }
}

bool Shape::shift(Dir dir){
  Cell* newLocs[numBlocks];
  for( int i = 0; i < numBlocks; ++i){
    newLocs[i] = squares[i].getLoc()->getNeighbour(dir);
  }
  if ( canMove(newLocs) ){
    for( int i = 0; i < numBlocks; ++i){
      squares[i].shift(dir);
    }
    loc = loc->getNeighbour(dir);
    return true;
  }
  return false;
}

void Shape::remove(){
  detach();
}
