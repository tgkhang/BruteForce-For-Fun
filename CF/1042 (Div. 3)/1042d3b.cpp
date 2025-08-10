#include <bits/stdc++.h>

using namespace std;

#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define FOR3(i, a, b) for (ll i = a; i <= b; ++i)
#define FOR4(i, a, b) for (ll i = a; i >= b; --i)
// note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto &x : a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

void run_case()
{
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 ;
        return;
    }

    vector<ll>res(n);

    
    if(n%2==0)
    {
        for(auto i=0;i<n;i+=2)
        {
           res[i]=-1;
        }
        int tmp=2;
        for(int i=n-1;i>=0;i-=2)
        {
            res[i]=tmp;
            if(tmp!=3)tmp++;
        }

    }
    else
    {
        for(auto i=0;i<n;i+=2)
        {
           res[i]=-1;
        }
        int tmp=2;
        for(int i=n-2;i>=0;i-=2)
        {
            res[i]=tmp;
            if(tmp!=3)tmp++;
        }
        res[n-2]++;
    }
    for(auto i: res)cout<<i<<" ";

}
void run_with_t()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
        cout << jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    run_with_t();
    // run_case();
    return 0;
}