/*
difference = abs (total - group_sum) - group_sum =| total - 2×group_sum |
to minimize we want
total == 2* group_sum
total is const
total/2 >= group_sum
*/
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int p[20];

	ll s = 0, ans = 0;

	for (int i = 0; i < n; ++i)
		cin >> p[i], s += p[i];

	// Iterate over all subsets (using bitmask from 0 to (1<<n)-1)
	for (int i = 0; i < 1 << n; ++i)
	{
		ll group_sum = 0;			// Current subset sum
		for (int j = 0; j < n; ++j) // go through all position
			if (i >> j & 1)			// Check if j-th apple is in subset
				group_sum += p[j];
		if (group_sum <= s / 2)
			ans = max(ans, group_sum);
	}

	cout << s - 2 * ans;
	return 0;
}