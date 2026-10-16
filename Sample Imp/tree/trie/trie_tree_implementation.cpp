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

};

//O(n): n is the length of the word to insert
void insert(TrieNode* root, const string& key){
    TrieNode* cur=root;

    for (char c:key){
        // check if the node exists for current character
        if(cur->child[c-'a'] == nullptr){
            cur->child[c-'a'] = new TrieNode();
        }

        // move to next 
        cur= cur->child[c-'a'];
    }
    cur->isLeaf=true;
}

// O(n): n is the length of the word to search
bool search(TrieNode* root, const string& key){
    TrieNode* cur= root;

    for(char c: key){
        if(cur->child[c-'a']==nullptr)return false;

        // move to next
        cur= cur->child[c-'a'];
    }

    return cur->isLeaf;
}

bool isPrefix(TrieNode *root, string &key){
    TrieNode *current = root;
    for (char c: key){
       if(current->child[c-'a']==nullptr)return false;
       current=current->child[c-'a'];
    }
    return true;
}

int main() {
    return 0;
}
