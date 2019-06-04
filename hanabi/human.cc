#include "human.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Action Human::takeTurn(){
  string cmd;
  while (cin >> cmd){
    if ( cmd == "hint" ){
      return giveHint();
    } else if ( cmd == "discard" ){
      return discardCard();
    } else if ( cmd == "play" ){
      return playCard();
    } else {
      cout << "Invalid command. Possible commands:\n   hint player num/colour\n   discard num\n   play num" << endl;
    }
  }
  return {'\0', 0, '\0'};
}

Action Human::giveHint(){
  Action act;
  act.play = 'H';
  string who;

  while ( cin >> who ){
    istringstream iss{who};
    if (iss >> act.who) break;
    cout << "Please select a player by number." << endl;  
  }

  cin >> act.what; 

  return act;
}

Action Human::discardCard(){
  return {'D', 0, 0};
}

Action Human::playCard(){
  return {'P', 0, 0};
}
