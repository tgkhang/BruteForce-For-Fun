#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  freopen("input.inp", "r", stdin);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> c(n), p(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> p[i];

    // dp: a = max points achievable per unit of current stamina
    // Process right to left
    double a = 0.0;
    for (int i = n - 1; i >= 0; i--) {
      double r = (100.0 - p[i]) / 100.0;
      // Take task i: gain c[i] + a * r (per unit stamina)
      // Skip task i: gain a (per unit stamina)
      a = max(a, c[i] + a * r);
    }

    // Initial stamina = 1, so answer = a * 1
    cout << fixed << setprecision(10) << a << "\n";
  }

  return 0;
}