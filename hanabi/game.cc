#include "game.h"
#include "action.h"

using namespace std;

Game::Game(int numPlayers){
  int numCards;
  if ( numPlayers < 4 ) numCards = 5;
  else numCards = 4;

  for ( int i = 0; i < numPlayers; ++i ){
    players.emplace_back(numCards);
  }

  for ( int i = 0; i < numCards; ++i ){
    for (unsigned int j = 0; j < players.size(); ++j ){
      players[j].drawCard(deck.draw());
    }
  }
}

void Game::play(){
  try {
    int turn = 0;
    while ( true ){
      for ( unsigned int play = 0; play < players.size(); ++play ){
        cout << "Player: " << play << endl;
        cout << players[play];
      }

      takeTurn(turn);

      turn = (turn + 1) % players.size();
    }
  } catch ( GameOver& g ){
    int score = 0;
    for ( int val: piles ){
      score += val;
    }
    cout << "Final Score: " << score << endl;
  }
}

void Game::takeTurn(int turn){
  Player* p = &players[turn];

  for ( unsigned int play = 0; play < players.size(); ++play ){
    if ( p != &players[play] ){
      // print each hand
      cout << "Player " << play  << ":" << endl;
      players[play].printHand();
      cout << endl;
    }
  }
  cout << "Complete your turn." << endl;

  while ( true ){
    Action action = p->takeTurn();
    cout << "after action" << endl;
    if ( action.play == 'H' ){
      if ( action.who == turn ) {
        cout << "You cannot give yourself a hint." << endl;
        continue;
      }
      char what = action.what;
      int hinted = 0;
      if ( what == '1' || what == '2' || what == '3' || what == '4' || what == '5' ){
        int hint = what - '0';
        hinted = players[action.who].getHint(hint);
      } else if ( what == 'B' || what == 'G' || what == 'R' || what == 'Y' || what == 'W' ){
        if ( what == 'B' ) hinted = players[action.who].getHint(Colour::blue);
        if ( what == 'G' ) hinted = players[action.who].getHint(Colour::green);
        if ( what == 'R' ) hinted = players[action.who].getHint(Colour::red);
        if ( what == 'Y' ) hinted = players[action.who].getHint(Colour::yellow);
        if ( what == 'W' ) hinted = players[action.who].getHint(Colour::white);
      } else {
        cout << "Invalid hint." << endl;
        continue;
      }
      if ( hinted == 0 ){
        cout << "A valid hint must involve at least one card which is present." << endl;
        continue;
      }
      // TODO: check that hint was a valid hint, decrease hint count -> must check hint count
      break;

    } else if ( action.play == 'D' ){
      break;
    } else if ( action.play == 'P' ){
      break;
    }
  }
}
