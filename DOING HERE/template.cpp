#include <bits/stdc++.h>

// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// s.find_by_order(2) order_of_key(9)
using namespace std;

// special data tructure
// #define NDEBUG
// #include <ext/pb_ds/assoc_container.hpp>// Common file
// using namespace __gnu_pbds;

// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

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
int d4i[] = {-1, 0, 1, 0};
int d4j[] = {0, 1, 0, -1};
int d8i[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d8j[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// operator =?
//  ko bit operator nên xài do kieeur data cung ko toi uu lam
/*
bool equal(auto x,auto y)
{
    if (abs(x-y) < 1e-9) return true;
    else return false;
}*/

/*
template<typename T>
void output_vector(const T &v,  int start = -1, int end = -1)
{
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] << (i < end - 1 ? ' ' : '\n');
}
*/

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

void run_case()
{
  int n;
  cin >> n;
    vector<string> R(n);
    FOR1(i,0,n) cin >> R[i];

    bool valid = true;

    // basic test
    // kiểm tra xem có phải tất cả R[i][i] đều là '1' không,
    // mỗi node phải có đường đi đến chính nó
    FOR1(i,0,n)
      if (R[i][i] != '1') {
        valid = false;
        break;
      }
  

    // Nếu R[i][j] = '1' và R[j][i] = '1' với i != j thì không hợp lệ
    // vì điều này sẽ tạo ra một khuyên giữa i và j => not a tree
    if (valid)
        FOR1(i,0,n)
            FOR1(j,i+1,n)
            if (R[i][j] == '1' && R[j][i] == '1') valid = false;
  
    // kiểm tra xem R có phải là quan hệ bắc cầu không,
    // nếu R[i][j] = '1' và R[j][k] = '1' thì R[i][k] cũng phải là '1'
    // nếu không thì R không phải là quan hệ bắc cầu => không thể là cây
    if (valid)
      for (int i = 0; i < n && valid; i++)
        for (int j = 0; j < n && valid; j++)
          if (R[i][j] == '1')
            for (int k = 0; k < n && valid; k++)
              if (R[j][k] == '1')
                if (R[i][k] != '1') valid = false;

    if (!valid) {
      cout << "No\n";
      return;
    }

    // kế tiếp tìm các cạnh trực tiếp trong cây,
    // một cạnh (u, v) là trực tiếp nếu R[u][v] = '1' và không tồn tại w khác u, v sao cho R[u][w] = '1' và R[w][v] = '1'
    vector<pair<int, int>> edges;
    FOR1(u,0,n) {
      FOR1(v,0,n) {
        if (u == v || R[u][v] != '1') continue;
        bool direct = true;
        FOR1(w,0,n)
          if (w == u || w == v) continue;
          else if (R[u][w] == '1' && R[w][v] == '1') direct = false;
        if (direct) edges.push_back({u, v});
      }
    }


    // 5. Check exactly n-1 edges
    if ((int)edges.size() != n - 1) {
      cout << "No\n";
      return;
    }

    // 6. Check it's a tree (connected, no cycle via union-find)
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x) {
      return par[x] == x ? x : par[x] = find(par[x]);
    };
    for (auto& [u, v] : edges) {
      if (!valid) break;
      int pu = find(u), pv = find(v);
      if (pu == pv) {
        valid = false;
        break;
      }
      par[pu] = pv;
    }
    if (valid) {
      int r = find(0);
      FOR1(i,1,n)
        if (find(i) != r) {
          valid = false;
          break;
        }
    }

    if (!valid) {
      cout << "No\n";
      return;
    }

    vector<vector<int>> adj(n);
    for (auto& [u, v] : edges) adj[u].push_back(v);

    for (int i = 0; i < n && valid; i++) {
      vector<bool> reach(n, false);
      reach[i] = true;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
          if (!reach[v]) {
            reach[v] = true;
            q.push(v);
          }
      }
      for (int j = 0; j < n && valid; j++)
        if ((R[i][j] == '1') != reach[j]) valid = false;
    }

    if (!valid) {
      cout << "No\n";
      return;
    }

    cout << "Yes\n";
    // endline except final line
    for (auto& [u, v] : edges)
  //  if(u == 0) cout << u + 1 << " " << v + 1;
    //else cout << jj << u + 1 << " " << v + 1;
     cout << u + 1 << " " << v + 1 << jj;

}

void run_with_t()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
        // cout << jj;
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