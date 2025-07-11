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
#define sz(x) (int)(x).size()// ??

void run_case()
{
    ll n,d,k;
    cin>>n>>d>>k;

    vector <ll>ss(n+1,0),es(n+1,0);

    FOR1(i,0,k-1)
    {
        ll l,r;
        cin>>l>>r;
        ss[l]++;
        es[r]++;
    }
    FOR1(i,1,n)
    {
        ss[i]=ss[i]+ss[i-1];
        es[i]=es[i]+es[i-1];
    }

    ll t1=-1;
    ll t2=1e18;
    ll res1=0,res2=0;
    for(ll i=d;i<=n;i++)
    {
        ll current= ss[i]-es[i-d];
        if(current>t1)
        {
            t1=current;
            res1=i-d+1;
        }
        if(current<t2)
        {
            t2=current;
            res2=i-d +1;
        }
    }   
    cout<<res1<<" "<<res2;
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


