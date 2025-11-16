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
#define EACH(x, a) for (auto &x : a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

void run_case()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) /// a tree n-1 edge
    {
        int u, v;
        cin >> u >> v;
        --u, --v; // init again start from 0
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2)
    {
        cout << 0 << "\n";
        return;
    }

    int cnt = 0; // number of vertex has degree 1
    for (int i = 0; i < n; ++i)
    {
        cnt += adj[i].size() == 1;
    }

    int ans = cnt - 1;

    // vertex i is the center of the star graph
    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        for (auto &j : adj[i])
        {
            t += adj[j].size() == 1;
        }
        // minus the number of leaf nodes connected to the center
        // a operation will handle all node in that branch
        ans = min(ans, cnt - t);
    }
    cout << ans << "\n";
}
void run_with_t()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
        cout << jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    run_with_t();
    // run_case();
    return 0;
}