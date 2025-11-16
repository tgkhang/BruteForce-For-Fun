#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord = false;
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *cur = root;

        for (char ch : word)
        {
            // if character do not exist
            if (cur->children.find(ch) == cur->children.end())
            {
                cur->children[ch] = new TrieNode();
            }
            // move to child node
            cur = cur->children[ch];
        }
        // mark end of word
        cur->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                return false; // Character not found
            }
            cur = cur->children[c];
        }
        return cur->isEndOfWord;
    }

    bool hasStringStartsWith(string prefix)
    {
        TrieNode *cur = root;
        for (char ch : prefix)
        {
            if (cur->children.find(ch) == cur->children.end())
            {
                return false;
            }
            cur = cur->children[ch];
        }

        return true;
    }
};

int main()
{
    return 0;
}