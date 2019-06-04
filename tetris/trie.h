#ifndef ___TRIE__H_
#define ___TRIE__H_

#include <string>
#include "command.h"

class Trie{
  class TrieNode;
  TrieNode* theTrie;

 public:
  Trie();
  ~Trie();

  bool insert(const std::string&, const std::string&);
  bool insert(const std::string&, Op op);
  Op find(const std::string&);

  void reset();
};

#endif
