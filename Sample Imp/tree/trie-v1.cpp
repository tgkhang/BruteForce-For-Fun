#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int K = 26;
struct Vertex
{
    int next[K];
    bool output = false;

    Vertex()
    {
        fill(begin(next), end(next), -1);
    }
};
vector<Vertex> trie(1);

void addString(string &s)
{
    int v = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        if (trie[v].next[c] == -1)
        {
            // trie[v].next[c] = trie.size(); // trie. size how many vertex exist
            // trie.emplace_back();           // This actually creates the new vertex and adds it to the vector use default constructor size +1

            int newVertexIndex = trie.size(); // Get index for new vertex
            trie[v].next[c] = newVertexIndex; // Store the pointer
            trie.emplace_back();              // Create the new vertex
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

int main()
{
    return 0;
}