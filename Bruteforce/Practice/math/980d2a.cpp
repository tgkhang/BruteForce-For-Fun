/*
link:https://codeforces.com/contest/2024/problem/A
Codeforces Round 980 (Div. 2) A
20/10/2024
rating:900
*/

#include<bits/stdc++.h>

using namespace std;

#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define for1(i,a,b) for(ll i=a;i<b;++i)
#define for2(i,a,b) for(ll i=a;i>b;--i)
#define for3(i,a,b) for(ll i=a;i<=b;++i)
#define for4(i,a,b) for(ll i=a;i>=b;--i)
//note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto& x: a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)


typedef long long ll;
typedef long double ld;
const ll base=1e9+7;
const float pi=3.1415926535897932384626433;
typedef pair<ll,ll> PLL;
typedef unsigned long long  ULL;



#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int)(x).size()// ??
void run_case()
{
	//a-t >= b - 2t
    ll a,b;
    cin>>a>>b;

    if(a>=b) cout<<a;
    else
    {
        ll t=b-a;
        if(t>a)cout<<0;
        else 
        {
            cout<<a-t;
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
