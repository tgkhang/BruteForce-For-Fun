// let the second array sorted

#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n)
    {
        cout << "NO\n";
        return;
    }

    // 1 0 1
    if ((a == 0 || b == 0) && (a + b) > 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES" << endl;
    ll draws = n - (a + b);
    ll t = n - draws; // number of not draw round

    // win round


    // ITER BY VALUE
    // for (int i = b + 1; i <= t; ++i)
    //  cout << i << " ";

    // ITER BY INDEX
    int tmp = b + 1;
    for (int i = 1; i <= a; ++i)
    {
        cout << tmp++ << " ";
    }

    // lose round
    // LOOK HERE FIRST
    for (int i = 1; i <= b; ++i)
        cout << i << " ";

    // equal part
    for (int i = t + 1; i <= n; ++i)
        cout << i << " ";

    cout << endl;

    // second array
    for (int i = 1; i <= n; ++i)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}