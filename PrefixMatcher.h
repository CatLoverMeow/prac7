#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>
#include "TrieNode.h"

class PrefixMatcher {
    protected:
    TrieNode* root;
    public:
    PrefixMatcher();
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);
};

#endif
