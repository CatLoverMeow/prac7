#ifndef Autocomplete_H
#define Autocomplete_H
#include <vector>
#include <string>
#include "TrieNode.h"
class Autocomplete{
    protected:
    TrieNode* root;
    void getAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions);
    public:
    Autocomplete();
    std::vector<std::string> getSuggestions(const std::string& partialWord);
    void insert(const std::string& word);
};

#endif