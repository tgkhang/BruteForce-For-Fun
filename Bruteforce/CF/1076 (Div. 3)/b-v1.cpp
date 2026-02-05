/**
 * Complexity : O(n^2) in worst case
 */

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

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

void printRes(vector<int> &t)
{
    for (auto i : t)
        cout << i << " ";
}

void run_case()
{
    int n;
    cin >> n;
    vector<int> a(n);

    FOR1(i, 0, n)
    cin >> a[i];

    int l = -1;
    int maxVal = -1;

    FOR1(i, 0, n - 1)
    {
        int maxRight = *max_element(a.begin() + i + 1, a.end());
        if (maxRight > a[i])
        {
            l = i;
            maxVal = maxRight;
            break;
        }
    }

    if (l == -1)
    {
        printRes(a);
        return;
    }

    int r = l + 1;
    FOR1(i, l + 1, n)
    if (a[i] == maxVal)
        r = i;

    reverse(a.begin() + l, a.begin() + r + 1);
    printRes(a);
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