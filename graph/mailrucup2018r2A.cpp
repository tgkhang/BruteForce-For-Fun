//900


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

ll n,m;
ll a[1001][1001],dd[1001][1001];

ll dfs(ll i,ll j)
{
    ll res=a[i][j];
    dd[i][j]=true;
    //i+1,j
    if(i!= n-1 && dd[i+1][j]==false && a[i+1][j]!=0 )
    res+= dfs(i+1,j);
    //i,j+1
    if(j!=m-1 && dd[i][j+1]==false && a[i][j+1]!=0)
    res+=dfs(i,j+1);
    //i-1,j
    if(i!=0 && dd[i-1][j]==false && a[i-1][j]!=0)
    res+=dfs(i-1,j);
    //i,j-1
    if(j!=0 && dd[i][j-1]==false && a[i][j-1]!=0)
    res+=dfs(i,j-1);
    return res;
}


void run_case()
{
    ll n,s;
    cin>>n>>s;
    ll a[n],b[n];
    FOR1(i,0,n)cin>>a[i];
    FOR1(i,0,n)cin>>b[i];

    if(a[0]==0){cout<<"NO";return;}

    if(a[s-1]==1){cout<<"YES";return;}

    if(b[s-1]==0){cout<<"NO";return;}
    

    for(ll i=n-1;i>s-1;--i)
    {
        if(a[i]==1&&b[i]==1){cout<<"YES";return;}
    }
    cout<<"NO";

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