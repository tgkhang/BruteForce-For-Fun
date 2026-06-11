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
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()  // ??

const int MAXN = 8000;
bitset<MAXN> row_bs[MAXN];

void run_case() {
  int n;
  cin >> n;
  vector<string> R(n);
  for (int i = 0; i < n; i++) cin >> R[i];

  // Build row bitsets only (no col_bs — avoids cache thrashing)
  for (int i = 0; i < n; i++) {
    row_bs[i].reset();
    for (int j = 0; j < n; j++)
      if (R[i][j] == '1')
        row_bs[i].set(j);
  }

  // Check diagonal
  for (int i = 0; i < n; i++)
    if (R[i][i] != '1') { cout << "No\n"; return; }

  // Check antisymmetry
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (R[i][j] == '1' && R[j][i] == '1') { cout << "No\n"; return; }

  // Sort by cnt DESCENDING — direct successors have largest cnt
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) cnt[i] = row_bs[i].count();
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int a, int b) { return cnt[a] > cnt[b]; });

  // Greedy: tìm direct SUCCESSORS cho mỗi node i
  // Duyệt S(i)\{i} theo cnt giảm dần. Node j có cnt lớn nhất trong remaining
  // chắc chắn là direct successor. Sau đó loại bỏ row_bs[j] (mọi thứ j reach được)
  // Chỉ dùng row_bs, không cần col_bs — O(n²) total
  vector<pair<int, int>> edges;
  edges.reserve(n);
  for (int i = 0; i < n; i++) {
    bitset<MAXN> remaining = row_bs[i];
    remaining.reset(i);
    for (int idx = 0; idx < n; idx++) {
      int j = order[idx];
      if (!remaining.test(j)) continue;
      edges.push_back({i, j});
      remaining &= ~row_bs[j];
    }
  }

  if ((int)edges.size() != n - 1) { cout << "No\n"; return; }

  // Union-find: check tree
  vector<int> par(n);
  iota(par.begin(), par.end(), 0);
  auto find = [&](int x) {
    while (par[x] != x) x = par[x] = par[par[x]];
    return x;
  };
  for (auto& [u, v] : edges) {
    int pu = find(u), pv = find(v);
    if (pu == pv) { cout << "No\n"; return; }
    par[pu] = pv;
  }

  // BFS verification — O(n²)
  vector<vector<int>> adj(n);
  for (auto& [u, v] : edges) adj[u].push_back(v);

  vector<int> q;
  q.reserve(n);
  for (int i = 0; i < n; i++) {
    bitset<MAXN> reach;
    reach.set(i);
    q.clear();
    q.push_back(i);
    for (int qi = 0; qi < (int)q.size(); qi++) {
      int u = q[qi];
      for (int v : adj[u])
        if (!reach.test(v)) {
          reach.set(v);
          q.push_back(v);
        }
    }
    if (reach != row_bs[i]) { cout << "No\n"; return; }
  }

  cout << "Yes\n";
  for (auto& [u, v] : edges)
    cout << u + 1 << " " << v + 1 << "\n";
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

  run_with_t();
  // run_case();
  return 0;
}