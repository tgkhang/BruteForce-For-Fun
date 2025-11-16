#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> arr(n);

	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	arr[0] = x;
	for (int i = 1; i < n; ++i)
	{
		arr[i] = (a * arr[i - 1] + b) % c;
	}

	ll res = 0, cur = 0;

	for (int i = 0; i < k; ++i)
		cur += arr[i];
	res = cur;
	//cout << res << " ";
	for (int i = k; i < n; ++i)
	{
		cur += arr[i];
		cur -= arr[i - k];
		res ^= cur;
	}
	cout << res;
	return 0;
}