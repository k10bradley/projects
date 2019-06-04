#include "trie.h"
#include <vector>
#include "command.h"
#include <memory>
#include <iostream>

using namespace std;

char translate(char in){
  if ( 'a' <= in && 'z' >= in ) return in - 'a';
  else return in - 'A' + 26;
}

struct Trie::TrieNode{
  Op op = NONE;
  vector<TrieNode*> children;
  bool final = false;
  
  TrieNode(const string& cmd = "", Op op = NONE);
  ~TrieNode();

  bool insert(const string&, Op);
  Op find(const string&);
};
  
Trie::TrieNode::TrieNode(const string& cmd , Op oper ): op(oper), children(52,nullptr){
  if ( ! cmd.empty() ){
    char let = translate(cmd[0]);
    children[let] = new TrieNode(cmd.substr(1), oper);
  } else {
    final = true;
  }
}

Trie::TrieNode::~TrieNode(){
  for ( auto child: children ) delete child;
}


bool Trie::TrieNode::insert(const string& cmd, Op operation){
  char first = translate(cmd[0]);
  if ( first < 0 || first > 51 ) return false;
  if ( children[first] ){
    if ( children[first]->op != NONE && !children[first]->final ){
      children[first]->op = NONE;
    }
    if ( cmd.substr(1).empty() ){
      children[first]->op = operation;
    } else {
      children[first]->insert(cmd.substr(1), operation);
    }
  } else {
    children[first] = new TrieNode(cmd.substr(1), operation);
  }
  return true;
}

Op Trie::TrieNode::find(const string& cmd){
  char first = translate(cmd[0]);
  if ( children[first] ){
    if ( children[first]->op != NONE ){
      return children[first]->op;
    } else {
      return children[first]->find(cmd.substr(1));
    }
  }
  return NONE;
}

bool Trie::insert(const string& old, const string& add){
  if ( find(add) ) return false;
  Op oper = find(old);
  if ( oper == NONE ) {
    cerr << old << " is not a command" << endl;
    return false;
  }
  bool result = theTrie->insert(add, oper);
  if ( !result ) cerr << add << " is not a valid command" << endl;
  return result;
}

bool Trie::insert(const string& add, Op oper){
  if ( find(add) == oper ) return false;
  return theTrie->insert(add, oper);
}

Op Trie::find(const string& cmd){
  if ( theTrie == nullptr ) return NONE;
  return theTrie->find(cmd);
}

void Trie::reset(){
  delete theTrie;
  theTrie = new TrieNode;
}

Trie::Trie(): theTrie{new TrieNode} {}
Trie::~Trie(){ delete theTrie; }
