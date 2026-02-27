#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<stdio.h>
#include<set>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cmath>
#include<list>
#include<stdlib.h>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<climits>
//????
#include<array>
#include<bitset>
#include<cassert>
#include<chrono>
#include<cstring>
#include<functional>
#include<numeric>
#include<random>


using namespace std;

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
#define EACH(x, a) for (auto& x: a)
#define jj "\n"

typedef long long ll;
typedef long double ld;
const ll base=1e9+7;
const float pi=3.1415926535897932384626433;
typedef pair<ll,ll> PLL;
typedef unsigned long long  ULL;

void run_case()
{
    ll n,k;

    cin>>n>>k;
    vector<vector<ll>> adj(n); // () not [] like in the book

    FOR1(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto check = [&] (int x)
    {
        int res=0;
        //res is the number of component can be cut

        auto dfs=[&] (auto func, int current, int parent)-> int
        {
            int numvertex=1;
            //number of vertex in the current coponent

            for(auto i: adj [current])
            {
                if(i==parent)continue;
                numvertex+= func(func,i,current);
            }
            if(numvertex >=x && current != parent)
            {

                res++;
                numvertex=0;
            }
            return numvertex;
        };

        //t is the number of vertex in the last coponent
        int t=dfs(dfs,0,0);


        //res >k : cut many component can be merge
        if(res>k ||  (res==k && t >= x))return true;
        else return false;

    };


    //???
    int low=1,high= n/(k+1)+1;
    while(high-low >1)
    {
        int mid= low + (high-low)/2;
        if(check(mid))
        {
            low=mid;
        }
        else high=mid;
    }
    cout<<low;
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


