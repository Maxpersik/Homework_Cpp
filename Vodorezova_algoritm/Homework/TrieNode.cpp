#include <iostream>
#include <unordered_map>
#include <string>
#include "Trie.h"
#include "TrieNode.h"

TrieNode::TrieNode() {
    isEndOfWord = false;
}
TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second; // ������� ��� �������� ����
    }
}
