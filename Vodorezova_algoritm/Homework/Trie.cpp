#include <iostream>
#include <unordered_map>
#include <string>
#include "Trie.h"
#include "TrieNode.h"

Trie::Trie() {
    root = new TrieNode();
}

// Вставка слова в префиксное дерево
void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        // Если символа нет в дочерних узлах, добавляем его
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    // Помечаем конец слова
     node->isEndOfWord = true;
}

// Поиск слова в префиксном дереве
bool Trie::search(const std::string & word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }
        node = node->children[ch];
    }
    return node->isEndOfWord;
}

// Проверка наличия префикса в префиксном дереве
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
    delete root; // Удаляем корень, который рекурсивно удалит все дочерние узлы
    
}

