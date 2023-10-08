#ifndef TrieNode_H
#define TrieNode_H
#include <vector>

class TrieNode{
    public:
    TrieNode* children[26];
    std::vector<TrieNode*> children_P;
    bool isEndOfWord;
    int routerNumber;
    TrieNode();
};

#endif