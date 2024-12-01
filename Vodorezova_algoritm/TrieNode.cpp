#include <iostream>
#include <unordered_map>
#include <string>
#include "function_by_Vodorezova.h"
#include "TrieNode.h"

TrieNode::TrieNode() {
    isEndOfWord = false;
}
TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second; // Удаляем все дочерние узлы
    }
}
