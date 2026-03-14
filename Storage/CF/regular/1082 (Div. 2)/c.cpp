/*
3 
best case: 1 1 2 2 3 3
worst case: 1 2 3 2 3 1

need to see out that worst case :
1 2 1 3 2 3
*/

#include <bits/stdc++.h>
using namespace std;

#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define jj "\n"

#define space printf(" ")

typedef long long ll;

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()  // ??

void run_case() {
  long long n, k;
  cin >> n >> k;

  // best case, worst case
  if (k < n || k > 2 * n - 1) {
    cout << "NO";
    return;
  }

  cout << "YES" << jj;
  int m = k - n + 1;  // telescope uses m pairs, gives 2m-1 turns

  // Telescope: [1, 2, 1, 3, 2, 4, 3, ..., m-1, m, m-1, m]
  cout << 1;
  for (int j = 1; j <= m - 1; j++)
    cout << " " << (j + 1) << " " << j;
  cout << " " << m;


  // Adjacent pairs for remaining n-m values
  for (int i = m + 1; i <= n; i++)
    cout << " " << i << " " << i;
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