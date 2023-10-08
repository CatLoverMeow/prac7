#include "TrieNode.h"
using namespace std;

TrieNode::TrieNode(){
    isEndOfWord = false;
    routerNumber = -1;
    children_P = vector<TrieNode*>(2, nullptr);
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}