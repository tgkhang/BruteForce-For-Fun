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

void solve(int i, int n, string s, set<string> &res)
{
	if (i == n)
	{
		res.insert(s);
		return;
	}

	for (int j = 0; j < n; ++j)
	{
		//try check to reduce complex
		 if (j > i && s[j] == s[i]) continue;

		swap(s[i], s[j]);
		solve(i + 1, n, s, res);
		swap(s[i], s[j]);
	}
}

int main()
{

	string s;
	cin >> s;
	int n = s.size();
	set<string> res;

	// string cur;
	solve(0, n , s, res);

	cout << res.size() << endl;
	for (auto i : res)
		cout << i << endl;

	return 0;
}