
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            if (i >= j)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
