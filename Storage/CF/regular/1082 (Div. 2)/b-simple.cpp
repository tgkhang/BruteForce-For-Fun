/*
Notice: no matter string T is 'ababab...' or 'bababa'
- after each step, first and last character will be distinct

if n even: 'ababab'
- Step 1: first is different last, s1 can chose a or b
- Step 2: first = last -> s2 need to be different with s1
- step 3: first != last -> s3 can be = or != s2
- step 4: first = last -> s4 need to be different with s3

=> s[2i -1] != s[2i]

if n odd:  'ababa'
- Step 1: first = last, only 1 option
- Step 2: first != last -> s2 can be = or != s1
- Step 3: first = last -> s3 need to be different with s2

=> s[2i] != s[2i + 1]

*/

#include <bits/stdc++.h>
using namespace std;
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define jj "\n"

typedef long long ll;

void run_case() {
  ll n;
  string x;
  cin >> n >> x;

  bool ok = true;

  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      if (i + 1 >= n) break;
      if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
        ok = false;
        break;
      }
    }
  } else {
    if (x[0] == 'b') ok = false;
    for (int i = 1; i < n; i += 2) {
      if (i + 1 >= n) break;
      if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
        ok = false;
        break;
      }
    }
  }

  cout << (ok ? "YES" : "NO");
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