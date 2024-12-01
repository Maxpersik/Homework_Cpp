#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "function_by_Vodorezova.h"
#include "TrieNode.h"

class TrieNode
{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
    ~TrieNode();
};

