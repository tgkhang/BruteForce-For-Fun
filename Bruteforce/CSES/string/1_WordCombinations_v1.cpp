/*
    ababc
    4
    ab
    abab
    c
    cb
    output: 2
*/
#include <iostream>
using namespace std;
typedef long long ll;

#define ar array

const int mxN = 5e3, mxM = 1e6, M = 1e9 + 7;
int n, k;
string s, a[mxM];

int dp[mxN + 1];

int main()
{
    cin >> s;
    n = s.size();
    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    dp[0] = 1; // 1 way to create string with length 0

    for (int i = 1; i <= n; ++i) // go through index of s
    {
        for (int j = 0; j < k; ++j) // go through each substring
        {
            bool ok = i >= a[j].size();

            for (int l = 0; l < a[j].size() && ok; ++l) // go through value of substring
            {
                ok &= s[i - a[j].size() + l] == a[j][l];
            }

            if (ok)
            {
                dp[i] = (dp[i] + dp[i - a[j].size()]) % M;
            }
        }
    }
    cout << dp[n];

    return 0;
}