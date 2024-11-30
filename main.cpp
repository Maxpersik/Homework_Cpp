#include <iostream>
#include <unordered_map>
#include <string>
#include "Trie.h"
#include <vector>
#include "TrieNode.h"
#include "Utils.h"
#include "test.h"


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
    std::string command;
    long value;
    while (true) {
        displayMenu(getMenuOptions);
        getline(std::cin, command);
        
        value = numberOrDefault(command);
        
        switch (value) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                Trie trie;
                string poisk;
                vector<string> words = { "apple", "app", "banana" };
                poisk = "apple";
                prefix_code_by_Vodorezova(words, poisk);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
    

