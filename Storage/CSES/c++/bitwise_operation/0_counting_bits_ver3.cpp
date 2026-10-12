#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Count per bit column instead of per number: O(log n).
// For bit k over 0..n, the pattern is 2^k zeros then 2^k ones (period 2^(k+1)).
int main()
{
	ll n;
	cin >> n;
	ll total = n + 1; // numbers 0..n
	ll res = 0;
	for (int k = 0; (1LL << k) <= n; ++k)
	{
		ll half = 1LL << k;
		ll period = half << 1;
		res += (total / period) * half;          // full periods
		res += max(0LL, total % period - half);  // leftover part
	}
	cout << res;
}
