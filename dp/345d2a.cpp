using namespace std;

#include<bits/stdc++.h>

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
    ll a,b;
    cin>>a>>b;
    ll res=0;
    while(a>0&& b>0)
    {
        if(a==1 && b==1 )break;

        res++;

        if(a>b)
        {
            a-=2;
            b++;
        }
        else {
            b-=2;a++;
        }
    }
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



    //run_with_t();
    run_case();
    return 0;
}


