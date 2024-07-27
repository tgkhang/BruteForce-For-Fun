#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<stdio.h>
#include<set>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cmath>
#include<list>
#include<stdlib.h>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<climits>
//????
#include<array>
#include<bitset>
#include<cassert>
#include<chrono>
#include<cstring>

using namespace std;

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
#define EACH(x, a) for (auto& x: a)
#define jj "\n"


typedef long long ll;
typedef long double ld;
const ll base=1e9+7;
const float pi=3.1415926535897932384626433;
typedef pair<ll,ll> PLL;
typedef unsigned long long  ULL;

void run_case()
{
    ll n;
	cin>>n;
	vector<ll> a(n);

	int resxor=0;
	cin>>a[0];
	resxor=a[0];
	FOR1(i,1,n-1)
	{
	    cin>>a[i];
	    resxor= resxor ^ a[i];
	}

	if(n%2!=0)
    {
        cout<<resxor;
    }
    else
    {
        //n even
        if(resxor==0)cout<<1;
        else cout<<-1;
    }



}
void run_with_t()
{
    int t;
    cin>>t;
    while(t--)
    {
        run_case();
        cout<<jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE



    run_with_t();
    //run_case();
    return 0;
}


