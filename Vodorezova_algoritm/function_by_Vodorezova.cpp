#include <iostream>
#include <unordered_map>
#include <string>
#include "function_by_Vodorezova.h"
#include "TrieNode.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }
        node = node->children[ch];
    }
    return node->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }
        node = node->children[ch];
    }
    return true;
}
Trie::~Trie() {
    delete root;

}

