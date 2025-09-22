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
#include<stdlib.h>
#include<cstdlib>

#include<array>
#include<bitset>
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

//#define all(a) a.begin(), a.end()

void run_case()
{
    ll n;
    cin>>n;
    ll a[n];
    FOR1(i,0,n-1)cin>>a[i];

    ll res=1;
    ll tmp=a[0];
    ll i=0;

    //kĩ thuật chạy lại phần tử i,
    //tránh vướng số cuối không check  khi i >=n

    //while(i<n)
    for(;i<n;i++)
    {
        tmp=tmp&a[i];
        if(tmp==0)
        {
            if(i<n-1)//ko tách số cuối thành 1 mảng vì nó != 0
            {
                res++;
                tmp=a[i+1];
            }
        }
        else
        {        }
        //i++;
    }

    if(tmp!=0)res--;

    res=max(res,1LL);

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