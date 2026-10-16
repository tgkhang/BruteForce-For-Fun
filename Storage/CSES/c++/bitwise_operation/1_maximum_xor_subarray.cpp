#include <bits/stdc++.h>
using namespace std;

const int MAX_BIT = 30; 

struct TrieNode {
    int child[2];
    TrieNode() {
        child[0] = child[1] = -1;
    }
};

vector<TrieNode> trie;

void insert(int x) {
    int node = 0;
    for (int b = MAX_BIT; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (trie[node].child[bit] == -1) {
            trie[node].child[bit] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].child[bit];
    }
}

int queryMax(int x) {
    int node = 0;
    int res = 0;
    for (int b = MAX_BIT; b >= 0; b--) {
        int bit = (x >> b) & 1;
        int want = bit ^ 1;  // muốn bit ngược lại để XOR = 1
        if (trie[node].child[want] != -1) {
            res |= (1 << b);
            node = trie[node].child[want];
        } else {
            node = trie[node].child[bit];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    trie.reserve((n + 1) * (MAX_BIT + 1));
    trie.emplace_back();  // root = node 0

    insert(0);  // p[0] = 0

    int prefix = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix ^= x;
        ans = max(ans, queryMax(prefix));
        insert(prefix);
    }

    cout << ans << '\n';
    return 0;
}