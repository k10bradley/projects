#include "trie.h"
#include <iostream>

using namespace std;

int main(){
  Trie t;
  t.insert("test", UP);
  Op oper = t.find("test");
  if ( oper == UP ){
    cout << "success" << endl;
  }
  t.insert("testing", DOWN);
  Op oper2 = t.find("test");
  if ( oper2 == UP ){
    cout << "success" << endl;
  }
}
