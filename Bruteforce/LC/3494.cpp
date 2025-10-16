#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[i][j] time for ith wizzard to finish j-th potion
ll minTime2d(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size(), m = mana.size();
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            // times[i][j]=max(times[i−1][j],times[i][j−1])+skill[i]×mana[j]
            // need wizard i-1 finish the j potion ,and wizard i also complete previous potion
            ll t1 = (i > 0) ? dp[i - 1][j] : 0;
            ll t2 = (j > 0) ? dp[i][j - 1] : 0;

            dp[i][j] = max(t1, t2) + skill[i] * mana[j];
        }
    }

    return dp[n - 1][m - 1];
}

// dp[i] === dp[i][j-1]
// cur === dp[i-1][j]
// dp[i+1] == dp[i+1][j]
ll minTime(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size(), m = mana.size();
    vector<ll> dp(n);
    for (int j = 0; j < m; j++)
    {
        ll cur_time = 0;
        for (int i = 0; i < n; i++)
        {
            cur_time = max(cur_time, dp[i]) + skill[i] * mana[j];
        }
        dp[n - 1] = cur_time;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] - skill[i + 1] * mana[j];
        }
    }
    return dp[n - 1];
}

long long minTime1d(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size(), m = mana.size();
    vector<long long> done(n + 1, 0);
    // done[i] : time for first i wizards to finish j-1 potions

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
            done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];

        for (auto i : done)
            cout << i << " ";
        cout << endl;

        // make sure it is passed immediately
        for (int i = n - 1; i > 0; --i)
            done[i] = done[i + 1] - 1LL * mana[j] * skill[i];

        for (auto i : done)
            cout << i << " ";
        cout << endl;
        cout << endl;
    }

    return done[n];
}

int main()
{
    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana = {5, 1, 4, 2};

    cout << minTime2d(skill, mana);

    return 0;
}