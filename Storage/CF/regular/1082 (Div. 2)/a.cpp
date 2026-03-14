/*
Category: Math
assumpt: move a times method 1, b times method 2, c times method 3
condition: a >=0, b >= 0, c >= 0

x= 2a + 3b +4c
y = a -c

=> a = y + c >=0  => FIRST CONDITION : c >= max(0, -y)
x= 2(y+c) +3b +4c = 
x-2y = 3b + 6c = 3(b + 2c) => THIRD CONDITION : x-2y is divisible by 3


after that have 2 :
c>= max(0,-y) and  b = (x-2y-6c)/3 >=0 or x-2y-6c >=0

Case 1 : y>=0
=> c>=0 , assume c=0 => b = x-2y >=0 => SECOND CONDITION : x >= 2y

Case 2 : y<0
 => c>=-y , assume c=-y => b = (x-2y+6y)/3 = (x+4y)/3 >=0
 <=> x+4y >=0
 => SECOND CONDITION : x >= -4y


*/

#include <bits/stdc++.h>
using namespace std;

#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define EACH(x, a) for (auto& x : a)
#define jj "\n"

typedef long long ll;

void run_case() {
  ll x, y;
  cin >> x >> y;

  if ((x - 2 * y) % 3 == 0 && x >= max(2 * y, -4 * y))
    cout << "YES";
  else
    cout << "NO";
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