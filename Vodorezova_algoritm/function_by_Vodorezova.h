#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "function_by_Vodorezova.h"
#include "TrieNode.h"

class Trie
{
	friend class TrieNode;
private:
	TrieNode* root;
public:
	Trie();
	void insert(const std::string& word);
	bool search(const std::string& word);
	bool startsWith(const std::string& prefix);
	~Trie();
};
