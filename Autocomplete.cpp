#include "Autocomplete.h"
#include <cstring>
//#include <iostream>
using namespace std;


Autocomplete::Autocomplete() {
    root = new TrieNode();
}

vector<string> Autocomplete::getSuggestions(const std::string& partialWord){
    std::vector<std::string> suggestions;
    TrieNode* current = root;
    for (char ch : partialWord) {
        int index = ch - 'a';
        //cout << ch << " and " << index << endl;
        if (!current->children[index])
            return suggestions;
        current = current->children[index];
    }
    getAllWords(current, partialWord, suggestions);
    return suggestions;
}

void Autocomplete::insert(const std::string& word){
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index])
            current->children[index] = new TrieNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void Autocomplete::getAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions){
    //cout << "string inside getallwords: " << prefix << endl;
    if (node->isEndOfWord)
        suggestions.push_back(prefix);
    // cout << "suggestion: " << suggestions[0] << endl;
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char ch = 'a' + i;
            //cout << "ch inside getAllwords: " << ch << endl;
            getAllWords(node->children[i], (prefix + ch), suggestions);
        }
    }
}