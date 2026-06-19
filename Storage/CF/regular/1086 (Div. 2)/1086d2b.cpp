#include <bits/stdc++.h>
using namespace std;

#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define FOR3(i, a, b) for (ll i = a; i <= b; ++i)
#define FOR4(i, a, b) for (ll i = a; i >= b; --i)
// note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto &x : a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;


#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

void run_case()
{
	ll n,k,p,m;
	// n numberof card
    // k number can play initial
    // p win condition
    // m initial mana
	// a[i] cost for that card at initial step
 
	cin>>n>>k>>p>>m;
	vector<ll> a(n);
	FOR1(i,0,n)cin>>a[i];

	// create a viral for inital cost which is the value ap-1
	// tmp = ap-1
	ll pValue= a[p-1];
	ll initialCost= pValue;

	// if p>k => need to increase ccost innitial to match the process, remember to sort before adding
	if(p>k)
	{
		// p elements
		vector<ll> tmp(a.begin(),a.begin()+ p-1);
		sort(all(tmp));
		FOR1(i,0,p-k) initialCost += tmp[i]; 
	}

 	// if cost inital >m => no solution is made
	if(initialCost>m)
	{
		cout<<0;return;
	}

 	// create the cycle cost, initial that = ap-1
 	ll cycleCost= pValue;
	// n>k mmới cần tính thêm vốn quay dđầu
 	if(n>k)
 	{
 		vector<ll>tmp;
 		FOR1(i,0,n) if(i!= p-1) tmp.pb(a[i]);
 		sort(all(tmp));
 		FOR1(i,0,n-k) cycleCost+= tmp[i];
 	}

	cout << 1+ (m - initialCost)/ cycleCost;
}

void run_with_t()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
        cout << jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    run_with_t();
    // run_case();
    return 0;
}