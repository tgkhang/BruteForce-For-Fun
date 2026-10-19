// CF 4C - Registration system
#include <bits/stdc++.h>
using namespace std;
#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define FOR3(i, a, b) for (ll i = a; i <= b; ++i)
#define FOR4(i, a, b) for (ll i = a; i >= b; --i)
// note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto& x : a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const double pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;


#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()  // ??
class TrieNode {
    public:
    TrieNode* child[26];
    int cnt;

    TrieNode(): cnt(0) {fill(child, child + 26, nullptr);}
};

TrieNode* root = new TrieNode();

TrieNode* getNode(TrieNode* root, const string& key){
    TrieNode* cur = root;
    for(char c:key){
        if (cur->child[c - 'a'] == nullptr)
            cur->child[c - 'a'] = new TrieNode();
        cur = cur->child[c - 'a'];
    }
    return cur;
}

void run_case() {
  string s;
  cin >> s;

  TrieNode* node = getNode(root, s);
  if(node->cnt == 0){
      cout << "OK";
  }
  else cout << s << node->cnt;
  node->cnt++;
}

void run_with_t() {
    int t;
    cin >> t;
    while (t--) {
        run_case();
        cout << jj;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif  // ONLINE_JUDGE

    run_with_t();
    // run_case();
    return 0;
}

/*
    int n;
    cin >> n;

    map<string, int> mp;
    while (n--) {
        string s;
        cin >> s;
        if (mp[s] == 0) {
            cout << "OK\n";
        } else {
            cout << s << mp[s] << "\n";
        }
        mp[s]++;
    }
    return 0;
}
*/