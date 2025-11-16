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
	ll n;
	ll k;	
	cin>>n>>k;
	if(n==1){cout<<"NO";return;}	
	ll tmp;
	ll dem=0;
	if(n>=k)tmp=n-k+1;
	else 
	{	
		dem=1;
		tmp=1;
	}
	
    ll sole= n-tmp +1;
    if(sole%2==0)sole/=2;
    else
    {
        if(tmp%2==0)sole=sole/2;
        else sole=sole/2+1;
    }

	
	if(sole%2==0)cout<<"YES";
	else cout<<"NO";
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


