#include <iostream>
#include <unordered_map>
#include <string>
#include "function_by_Vodorezova.h"
#include "TrieNode.h"
#include <sstream>

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

bool prefix_code_by_Vodorezova(const std::string& text, const std::string& poisk) {
    Trie trie;

    // Разделение строки текста на слова
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        trie.insert(word);
    }

    // Проверка на точное совпадение или префикс
    bool isExactMatch = trie.search(poisk);
    bool isPrefixMatch = trie.startsWith(poisk);

    std::cout << "Output of search for word in text and prefix" << std::endl;
    std::cout << "Exact match: " << (isExactMatch ? "true" : "false") << std::endl;
    std::cout << "Starts with: " << (isPrefixMatch ? "true" : "false") << std::endl;

    // Возвращаем `true`, если есть либо точное совпадение, либо совпадение по префиксу
    return isExactMatch || isPrefixMatch;
}
