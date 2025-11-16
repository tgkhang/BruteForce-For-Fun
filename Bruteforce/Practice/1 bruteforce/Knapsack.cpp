#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C,n;
vector < ll > w;
vector < ll> v;

vector < ll > res;
vector < ll> current;
ll bestSol = 0;

void bruteForce(ll i, ll weight, ll value)
{
	if (i == n)
	{
		if(weight <= C && value > bestSol)
		{
			bestSol = value;
			res = current;
		}
		return;
	}

	bruteForce( i + 1, weight, value); // skip int

	current.push_back( i + 1);
	bruteForce( i + 1, weight + w[i],value + v[i]);
	current.pop_back();
}

int main()
{
	cin>>C;
	cin>>n;
	for( int i = 0 ; i < n; ++i ) {
		ll x, y;
		cin >> x >> y;
		w.push_back(x);
		v.push_back(y);
	}

	bruteForce(0,0,0);

	if( res.empty())
	{
		cout<<"No solution";
	}
	else {
		for( int i = 0 ; i < res.size() ; ++i ) cout << res[i] << " ";
		cout << bestSol << endl;
	}
	return 0;
}