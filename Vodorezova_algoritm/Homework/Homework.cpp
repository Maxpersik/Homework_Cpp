#include <iostream>
#include <unordered_map>
#include <string>
#include "Trie.h"
#include <vector>
#include "TrieNode.h"
using namespace std;

void prefix_code_by_Vodorezova(const vector<string>& words, string& poisk) {
    Trie trie;
    for (const auto& word : words) {
        trie.insert(word);
    }
    cout << "Output of search for word in template and prefix" << endl;
    cout << trie.search(poisk) << endl;
    cout << trie.startsWith(poisk) << endl;
    
}


int main() {
    Trie trie;
    string poisk;
    vector<string> words = { "apple", "app", "banana" };
    poisk = "apple";
    prefix_code_by_Vodorezova(words, poisk);
    return 0;
}
