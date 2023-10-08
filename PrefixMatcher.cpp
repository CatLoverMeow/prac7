#include "PrefixMatcher.h"
using namespace std;

PrefixMatcher::PrefixMatcher() {
    root = nullptr;
    root = new TrieNode();
}

int PrefixMatcher::selectRouter(string networkAddress) {
    TrieNode* current = root;
    int maxPrefixRouter = -1;
    for (size_t i = 0; i < networkAddress.length(); i++){
        char address = networkAddress[i];
        int index = address - '0';
        if (current->children_P[index] == nullptr){
            break;
        }
        current = current->children_P[index];
        if (current->routerNumber != -1){
            maxPrefixRouter = current->routerNumber;
        }
    }
    return maxPrefixRouter;
}

void PrefixMatcher::insert(string address, int routerNumber) {
    TrieNode* current = root;
    for (size_t i = 0; i < address.length(); i++){
        char addresses = address[i];
        int index = addresses - '0';
        if (current->children_P[index] == nullptr){
            current->children_P[index] = new TrieNode();
        }
        current = current->children_P[index];
    }
    current->routerNumber = routerNumber;
}

