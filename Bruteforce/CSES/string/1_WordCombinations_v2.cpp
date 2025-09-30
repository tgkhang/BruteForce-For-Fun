// Apply trie
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

#define ar array

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

    void insert(string &pattern)
    {
        TrieNode *current = root;
        for (char ch : pattern)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }
};

const int mxN = 5e3, mxM = 1e6, M = 1e9 + 7;
int n, k;
string s;

int dp[mxN + 1]; // number of ways to form the first i characters of string s

int main()
{
    cin >> s;
    n = s.size();
    cin >> k;
    Trie trie;
    for (int i = 0; i < k; ++i)
    {
        string tmp;
        cin >> tmp;
        trie.insert(tmp);
    }

    dp[0] = 1; // 1 way to create string with length 0

    for (int i = 0; i < n; ++i) // For each starting position
    {
        if (dp[i] == 0)
            continue; // no ways to reach position i

        TrieNode *cur = trie.root;

        // only need n-i character
        for (int j = 0; j < n - i && cur != nullptr; ++j)
        {
            char c = s[i + j];

            if (cur->children.find(c) == cur->children.end())
                break;

            cur = cur->children[c];
            if (cur->isEndOfWord)
            {
                dp[i + j + 1] = (dp[i + j + 1] + dp[i]) % M;
            }
        }
    }
    cout << dp[n];

    return 0;
}