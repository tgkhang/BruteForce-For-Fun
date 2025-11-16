#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int mxN = 5e3, mxM = 1e6, M = 1e9 + 7;

struct AC {
    int c[mxM + 1][26];      // children (trie edges)
    int d[mxM + 1][26];      // automaton transitions
    int sl[mxM + 1];         // suffix/failure link
    int ol[mxM + 1];         // output link
    int de[mxM + 1];         // depth at node
    int m = 1;               // node counter (0 is root, start from 1)
    
    // Insert pattern into trie
    void ins(string s) {
        int u = 0;
        for (char x : s) {
            if (!c[u][x - 'a'])
                c[u][x - 'a'] = m++;
            u = c[u][x - 'a'];
        }
        ol[u] = u;  // Mark pattern end
    }
    
    // Build Aho-Corasick automaton
    void ac() {
        queue<int> qu;
        qu.push(0);
        
        while (qu.size()) {
            int u = qu.front();
            qu.pop();
            
            for (int i = 0; i < 26; ++i) {
                if (c[u][i]) {
                    int v = c[u][i];
                    de[v] = de[u] + 1;
                    sl[v] = d[sl[u]][i];
                    
                    if (!ol[v])
                        ol[v] = ol[sl[v]];
                    
                    d[u][i] = v;
                    qu.push(v);
                } else {
                    d[u][i] = d[sl[u]][i];
                }
            }
        }
    }
} ac;

int n, dp[mxN + 1], k;
string s[mxM], t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t >> k;
    n = t.size();
    
    dp[0] = 1;
    
    for (int i = 0; i < k; ++i) {
        cin >> s[i];
        ac.ins(s[i]);
    }
    
    ac.ac();
    
    int u = 0;
    for (int i = 1; i <= n; ++i) {
        u = ac.d[u][t[i - 1] - 'a'];
        int v = ac.ol[u];
        
        while (v) {
            dp[i] = (dp[i] + dp[i - ac.de[v]]) % M;
            v = ac.ol[ac.sl[v]];
        }
    }
    
    cout << dp[n];
    
    return 0;
}