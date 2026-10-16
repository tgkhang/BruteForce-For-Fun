#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TrieNode {
   public:
    TrieNode* child[26];
    bool isLeaf;

    // constructor
    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
    
}



int main() {
    return 0;
}
