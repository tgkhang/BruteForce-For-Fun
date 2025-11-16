//tag dp, greedy, 800

#include<bits/stdc++.h>

using namespace std;

#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
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



void run_case()
{
    ll n;
    cin>>n;
    ll a[n];
    map<ll,ll> ma;
    FOR1(i,0,n-1)
    {
        cin>>a[i];
        ma[a[i]]++;
    }

    ll res=ma.size();
    //cout<<res<<jj;


    FOR2(i,n-1,0)
    {
        if(ma[a[i]+1]==0 )
        {
         ma[a[i]+1]++;
         ma[a[i]]--;
         if(ma[a[i]]!=0) res++;
         a[i]++;
        }
        //cout<<ma[4]<<jj;
    }
//    for(auto i: a)cout<<i<<" ";
//    cout<<jj;
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


