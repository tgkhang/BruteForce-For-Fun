#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<set>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<cstdlib>
#include<chrono>
#include<cstring>

using namespace std;


#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
#define EACH(x, a) for (auto& x: a)
#define jj "\n"

typedef long long ll;



ll finding(ll x)
{
    int c = 0;
    while ((x & 1) == 0)
    {
        x = x >> 1;
        c++;
    }
    return c;
}

void run_case()
{
    ll n,x;
    cin>>n;

    ll even=0,tmp=INT_MAX;
    FOR1(i,0,n-1)
    {
        cin>>x;
        //b[i]=finding(a[i]);
        if(x%2==0) {tmp= min(tmp,finding(x));
        even++;}
    }
    //cout<<even<<jj;
    // cout<<"t"<<tmp<<jj;

    if(even==0)
    {
        cout<<0;
    }
    else
    if(even==n)
    {
        cout<<tmp+even-1;
    }
    else
    {
        cout<<even;
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