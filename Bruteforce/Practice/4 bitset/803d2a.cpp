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


#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(),v.rend()

void run_case()
{
    ll n;
    cin>>n;
    vector<ll> a(n);

    cin>>a[0];
    ll tmp=a[0];

    FOR1(i,1,n-1)
    {
        cin>>a[i];
        tmp=tmp ^ a[i];
    }

    FOR1(i,0,n-1)
    {
        if( (tmp^a[i]) == a[i] )
        {

            cout<<a[i];
            return;
        }
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