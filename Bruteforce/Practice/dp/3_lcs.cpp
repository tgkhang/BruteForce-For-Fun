// longest common subsequence
/*
XYXZPQ
YXQYXP
Output:
XYXP
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n1, n2;
vector<int> a;
string s1, s2;
vector<vector<int>> dp;

void printResult(int i, int j)
{
    // stop
    if (i == 0 || j == 0)
        return;

    if (s1[i] == s2[j])
    {

        printResult(i - 1, j - 1);

        cout << s1[i];
    }
    else
    {
        if (dp[i][j] == dp[i - 1][j])
            printResult(i - 1, j);
        else
            printResult(i, j - 1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s1 >> s2;
    n1 = s1.length();
    n2 = s2.length();

    s1 = '.' + s1;
    s2 = '.' + s2;
    // cout<<s1<<endl<<s2;

    // vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    dp.resize(n1 + 1, vector<int>(n2 + 1, 0));

    for (size_t i = 1; i <= n1; ++i)
        for (size_t j = 1; j <= n2; ++j)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    cout << dp[n1][n2] << endl;
    printResult(n1, n2);

    return 0;
}