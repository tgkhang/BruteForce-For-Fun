#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.inp", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long wc_cost = a[p - 1];

    // Cost to play WC for the first time
    long long c_initial = wc_cost;
    if (p > k) {
      vector<int> before(a.begin(), a.begin() + p - 1);
      sort(before.begin(), before.end());
      for (int i = 0; i < p - k; i++)
        c_initial += before[i];
    }

    if (c_initial > m) {
      cout << 0 << "\n";
      continue;
    }

    // Cost per subsequent WC play: WC + n-k cheapest non-WC cards
    long long c_cycle = wc_cost;
    if (n - k > 0) {
      vector<int> others;
      for (int i = 0; i < n; i++)
        if (i != p - 1) others.push_back(a[i]);
      sort(others.begin(), others.end());
      for (int i = 0; i < n - k; i++)
        c_cycle += others[i];
    }

    cout << 1 + (m - c_initial) / c_cycle << "\n";
  }
  return 0;
}