#include<bits/stdc++.h>

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//s.find_by_order(2) order_of_key(9)
using namespace std;

//special data tructure
//#define NDEBUG
//#include <ext/pb_ds/assoc_container.hpp>// Common file
//using namespace __gnu_pbds;


//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


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
    cin>>n;
    ll a[n],sum=0;
    ll tmp=-1;
    FOR1(i,0,n-1)
    {   
        cin>>a[i];
        sum+=a[i];
        tmp=max(tmp,a[i]);
    }
    if(n<=2)
    {
        cout<<-1;
        return;
    }
    ll k=0;
    FOR1(i,0,n-1)
    {
        if(a[i]==tmp)k++;
    }
    
    sort(a,a+n);
    ll mid=n/2;
    mid=a[mid];
    

    ll res= (2*n*mid-sum);
    res+=1;
    if(res<0)cout<<0;
    else
    if(res<=mid){cout<<-1;return;}
    else cout<<res;
    //or res=max (0LL, formular)

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


