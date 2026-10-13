#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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


// For example, with n = 7 the numbers 0..7 are 000 to 111:
// - Bit 0 from 0-7: 01010101: 4 blocks of length 2 → 4 ones.
// - Bit 1 from 0-7: 00110011: 2 blocks of length 4 → 4 ones.
// - Bit 2 from 0-7: 00001111: 1 block of length 8 → 4 ones.
// - Total: 12.m, 
