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
#define FOR1(i,a,b) for(ll i=a;i<b;++i)
#define FOR2(i,a,b) for(ll i=a;i>b;--i)
#define FOR3(i,a,b) for(ll i=a;i<=b;++i)
#define FOR4(i,a,b) for(ll i=a;i>=b;--i)
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



//operator =?
// ko bit operator nên xài do kieeur data cung ko toi uu lam
/*
bool equal(auto x,auto y)
{
    if (abs(x-y) < 1e-9) return true;
    else return false;
}*/

/*
template<typename T>
void output_vector(const T &v,  int start = -1, int end = -1)
{
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] << (i < end - 1 ? ' ' : '\n');
}
*/

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int)(x).size()// ??


void run_case()
{
      ll n;
    cin>>n;
    vector<ll> a(n);
    ll tmp=0,vt=-1;

    vector<ll> res(n);

    FOR1(i,0,n)
    {
        cin>>a[i];
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