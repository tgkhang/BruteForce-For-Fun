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

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const double pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;
int d4i[] = {-1, 0, 1, 0};
int d4j[] = {0, 1, 0, -1};
int d8i[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d8j[] = {-1, 0, 1, 1, 1, 0, -1, -1};


#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()  

struct Node{
    Node* child[26];
    bool isEnd;
    Node() : isEnd(false) { fill(child, child + 26, nullptr); }
};

void insert(string& s) {
    Node* cur = root;
    for (char c : s) {
        if (cur->child[c - 'a'] == nullptr)
            cur->child[c - 'a'] = new Node();
        cur = cur->child[c - 'a'];
    }
    cur->isEnd = true;
}

Node* root;

void run_case() {
    string s;
    cin >> s;
    int n = s.length();

    int k;
    cin >> k;
    FOR1(i,0,k){
        string tmp;
        cin >> tmp;
        insert(tmp);
    }

    vector<ll> dp(n + 1, 0);

    FOR1(i,0,n){
        if(dp[i] == 0 )continue;

        Node* cur = root;

        FOR1(j,i,n){
            if(cur->child[s[j] - 'a'] == nullptr) break;
            cur = cur->child[s[j] - 'a'];
            if(cur->isEnd){
                dp[j + 1] += dp[i];
            }
        }
    }

    cout << dp[n] << jj;
}

void run_with_t() {
    int t;
    cin >> t;
    while (t--) {
        run_case();
        // cout << jj;
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

    //run_with_t();
     run_case();
    return 0;
}