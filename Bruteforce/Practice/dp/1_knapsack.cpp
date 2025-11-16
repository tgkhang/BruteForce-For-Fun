#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> v;
vector<int> w;


void printResult(int i,int j, vector<vector<int>>&dp)
{
    if(i==0)return ;
    if(j==0)return;

    if(w[i]>j) printResult(i-1,j,dp);
    else{
        if(dp[i][j]==dp[i-1][j])printResult(i-1,j,dp);
        else {
            printResult(i-1,j-w[i],dp);
            cout<<i<<" ";
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t >> n;
    v.resize(n + 1);
    w.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
    }

    // vector<vector<int>> dp(n + 1);
    // for (int i = 0; i < n; ++i)
    //     dp[i].resize(t);

    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            if (w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }


    printResult(n,t, dp);

    cout<<endl;
    cout << dp[n][t];

    return 0;
}