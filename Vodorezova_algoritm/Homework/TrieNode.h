#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Trie.h"
#include "TrieNode.h"

class TrieNode
{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
    ~TrieNode();
};

