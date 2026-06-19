#include <bits/stdc++.h>
using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    // Map to store frequency of each color
    map<int, int> freq;

    // Read the board and count frequencies
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int color;
        cin >> color;
        freq[color]++;
      }
    }

    int maxfreq = 0;
    for (auto& p : freq) {
      maxfreq = max(maxfreq, p.second);
    }

    // Check condition: if max frequency > n*(n-1), impossible
    if (maxfreq > n * (n - 1)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  freopen("input.inp", "r", stdin);
  cin.tie(NULL);

  solve();

  return 0;
}