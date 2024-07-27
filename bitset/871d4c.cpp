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
#include<array>
#include<bitset>
#include<cassert>
#include<chrono>
#include<cstring>
#include<functional>
#include<numeric>
#include<random>
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

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(),v.rend()

void run_case()
{
	ll n;
	cin>>n;
	vector<int>c1,c2,c3;
	FOR1(i,1,n)
	{
		string x;
		int t;
		cin>>t>>x;
		if(x=="01")
		{
			c1.pb(t);
		}
		else
        if(x=="10")
        {
            c2.pb(t);
        }
        else if(x=="11")
        {
            c3.pb(t);
        }
	}

	if( (c1.size()==0 or c2.size()==0)and c3.size()==0)
	{
		cout<<-1;
		return;
	}
	sort(all(c1));
	sort(all(c2));
	sort(all(c3));
	int res=INT_MAX;
	if(!c3.empty())res=min(res,c3[0]);
	if(!c1.empty()&& !c2.empty())
    res=min(res,c1[0]+c2[0]);
	cout<<res;

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


