
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int main()
{
    int n, x;

    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // dp[i] represent the minimum number of coins required to form the sum i.
    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; ++i)
    {
        for (auto j : a)
        {
            if (i >= j)
            {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }

    if (dp[x] > x)
    {
        cout << -1;
    }
    else
        cout << dp[x];

    return 0;
}
