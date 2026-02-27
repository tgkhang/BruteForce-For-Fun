#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> a;
int n;
int findx(int l, int r, int x)
{
	while (l <= r)
	{
		// int m=(l+r)/2;
		int m = l + (r - l) / 2;
		if (a[m].first == x)
			return m;
		if (a[m].first < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main()
{
	int x;
	//freopen("input.inp", "r", stdin);

	cin >> n >> x;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n - 1; ++i)
	{
		int t = findx(i + 1, n - 1, x - a[i].first);
		//cout << i << " " << t << " " << x - a[i].first << endl;
		if (t != -1)
		{
			if(a[i].second>a[t].second)swap(a[i],a[t]);
			cout << a[i].second+1 << " " << a[t].second+1;
			return 0;
		}
	}

	cout<<"IMPOSSIBLE";
	return 0;
}
