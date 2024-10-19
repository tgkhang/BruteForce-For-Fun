/*
link:https://codeforces.com/contest/2025/problem/C
Educational Codeforces Round 170 (Rated for Div. 2) C
17/10/2024
rating: 1100

tag: thinking, 2 pointer, sorting, brute force
*/

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
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for1(i,0,n)cin>>a[i];

    sort(a.begin(),a.end());

    ll res=0,t=0;
    //t is the second pointer and i is the first pointer
    for(ll i=0;i<n;i++)
    {
        t=max(i,t);
        while(t+1<n && a[t+1]-a[t]<=1 && a[t+1]-a[i]<k)
        t++;

        res=max(res,t-i+1);
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



    run_with_t();
    //run_case();
    return 0;
}
