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
#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
#define EACH(x, a) for (auto& x: a)
#define jj "\n"


typedef long long ll;
void run_case()
{
    ll n;
    cin>>n;


    int resmin=INT_MAX,resmax=0;
    FOR1(i,0,n-1)
    {
        int a;
        cin>>a;
        resmin &=a;
        resmax |= a;
    }


//    FOR1(i,0,9)
//    {
//        FOR1(j,0,n-1)
//        {
//            resmax=resmax | (a[j]& (1<<i));
//
////            auto t= ~((i>>i)&1);
////            resmin = resmin &(a[j] &~(t<<i));
//
//            int t1 = (resmin >> i) & 1;//take bit i~ of resmin
//            int t2 = (a[j] >> i) & 1;
//            t1= ~(t1 & t2);
//            t1= ~(t1<<i);
//
//            resmin = resmin & t1;
//        }
//
//    }

    //update bit i in resmin = i of res min & a[j]
    //cout<<resmax<<jj;
    //cout<<resmin<<jj;
    cout<<resmax-resmin;

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


