/*
Find minimum number of coins to make a given amount n using k different coin denominations.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> bestSol; // best solution
vector<ll> curSol;  // current solution
vector<ll> a;       // input value
ll n, k, curSum = 0;

void bruteForce(ll i, ll left, ll coinNum)
{
    if (i == k)
    { // check when the solution space is completed
        if (left == 0 && (curSum > coinNum || bestSol.empty()))
        {
            bestSol = curSol;
            curSum = coinNum;
        }
        return;
    }

    int t = left / a[i]; // maximum of ith coin

    for (int j = 0; j <= t; ++j)
    {
        curSol[i] = j;
        bruteForce(i + 1, left - j * a[i], coinNum + j);
    }
}

// update bruteforce
// you can sort the coins in descending order to optimize the search
void bruteForce2(ll i, ll left, ll coinNum)
{
    if (left < 0)
        return;

    if (i == k)
    { // check when the solution space is completed
        if (left == 0 && (curSum > coinNum || bestSol.empty()))
        {
            bestSol = curSol;
            curSum = coinNum;
        }
        return;
    }

    int t = left / a[i]; // maximum of ith coin

    for (int j = t; j >= 0; --j) // try larger first for early success
    {
        curSol[i] = j;

        // estimate the remaining amount
        ll remaining = coinNum + j + (left - j * a[i]) / a[k - 1];
        if (remaining >= curSum)
            continue; // skip if we already have a better solution

        bruteForce(i + 1, left - j * a[i], coinNum + j);
    }
}

void dynamicPrograming()
{
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[0] = 0; // base case: 0 coins to make amount

    for (ll i = 1; i <= n; ++i)
    {
        for (ll coin : a)
        {
            // i< coin means we cannot use this coin
            if (coin <= i && dp[i - coin] != LLONG_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[n] == LLONG_MIN)
    {
        cout << "No solution";
    }
    else
    {
        cout << "Max coins: " << dp[n] << endl;
    }
}

int main()
{
    cin >> k;

    for (auto i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        curSol.push_back(0);
    }

    cin >> n;
    bruteForce(0, n, 0);

    if (bestSol.empty())
    {
        cout << "No solution";
    }
    else
    {
        for (ll i = 0; i < k; ++i)
        {
            cout << a[i] << ": " << bestSol[i] << endl;
        }
    }
    return 0;
}