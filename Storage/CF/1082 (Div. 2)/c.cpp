#include <bits/stdc++.h>
using namespace std;

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
    int n; 
    string s;
    cin >> n >> s;
    
    int lo = 0, hi = 0, par = 0; // {0} = even in [0,0]
    bool ok = true;
    
    for (int i = 0; i < n && ok; i++) {
        char c = s[i];
        bool odd_step = (i + n) % 2 == 1;
        
        if (c == '?') { hi++; par = 2; }
        else if (odd_step) {
            // L=R: even->a, odd->b; matching p can go to p or p+1
            int target_par = (c == 'a') ? 0 : 1;
            if (par == target_par) { hi++; par = 2; }
            else if (par == 1 - target_par) { ok = false; }
            else { // par == 2
                int lo_t = lo + ((lo % 2) != target_par ? 1 : 0);
                int hi_t = hi - ((hi % 2) != target_par ? 1 : 0);
                if (lo_t > hi_t) { ok = false; break; }
                lo = lo_t; hi = hi_t + 1; par = 2;
            }
        } else {
            // L!=R: 'a'->all odd result, 'b'->all even result
            int res_par = (c == 'a') ? 1 : 0;
            int src_par = 1 - res_par; // even->'a'->odd, odd->'b'->even
            if (par == res_par) {
                // odd->p (c='a') or even->p (c='b'): stays
            } else if (par == src_par) {
                lo++; hi++; par = res_par;
            } else { // par == 2
                int new_lo = lo + (lo % 2 == (1-res_par) ? 1 : 0);
                int new_hi = hi + (hi % 2 == (1-res_par) ? 1 : 0);
                lo = new_lo; hi = new_hi; par = res_par;
            }
        }
    }
    
    // Check non-empty
    if (ok) {
        if (par == 2) ok = (lo <= hi);
        else ok = (lo + (lo % 2 != par ? 1 : 0)) <= hi;
    }
    cout << (ok ? "YES" : "NO");
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