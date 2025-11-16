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

void run_case()
{
   ll n;
   cin>>n;
   if(n==1){cout<<1<<jj<<1;return;}
    ll res[n];
    ll tmp=1;
    ll x=n,i=0;

    while(x>=tmp)
    {
        res[i]=tmp;
        x-=tmp;
        i++;tmp++;
    }

    if(x>0)res[i-1]+=x;
    cout<<i<<jj;
    for(int j=0;j<i;j++)cout<<res[j]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE


    run_case();
    return 0;
}


