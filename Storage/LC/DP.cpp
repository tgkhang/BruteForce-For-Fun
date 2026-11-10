#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 152. Maximum Product Subarray
 * =================================================================================================
 */

#include <bits/stdc++.h>
using namespace std;

/*

    int res = a[0], cur = a[0];
    for (int i = 1; i < a.size(); ++i) {

        cur = max(a[i], cur * a[i]);
        res = max(res, cur);
    }
    return res;

    not work; Kadane's algorithm works for maximum/minimum sum because:
    - A negative number always makes a sum smaller
    - We can simply "restart" when the running sum goes negative

    But with products, the rules are different:
    - A negative number can become positive when multiplied by another negative
    - Zero resets everything
*/

int maxProduct(vector<int> &a)
{
    int res = a[0];
    int curMax = a[0];
    int curMin = a[0]; // Track minimum too!

    for (int i = 1; i < a.size(); i++)
    {
        // When multiplying by negative, max and min swap!
        if (a[i] < 0)
        {
            swap(curMax, curMin);
        }

        curMax = max(a[i], curMax * a[i]);
        curMin = min(a[i], curMin * a[i]);

        res = max(res, curMax);
    }
    return res;
}

int main()
{
    return 0;
}

/**
 * =================================================================================================
 * 1277. Count Square Submatrices with All Ones
 * =================================================================================================
 */

// Count Square Submatrices with All Ones

/*
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


explain: https://www.youtube.com/watch?v=5Li-cR5h_uw
*/

#include <bits/stdc++.h>
using namespace std;

// dp[i][j] =x  : x*x is the maximum square can perform

int countSquares(vector<vector<int>> &a)
{
    // if(a==null || a.length==0)
    //     return 0;

    // normal case
    int m = a.size();
    int n = a[0].size();
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0 && a[i][j] > 0)
            {
                a[i][j] = min(min(a[i - 1][j], a[i][j - 1]), a[i - 1][j - 1]) + 1;
            }
            res += a[i][j];
        }
    }

    for (auto i : a)
    {

        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return res;
}
int main()
{
    vector<vector<int>> a = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};
    int res = countSquares(a);
    cout << res << endl;
    return 0;
}

/**
 * =================================================================================================
 * 1504. Count Submatrices With All Ones
 * =================================================================================================
 */

// Count Rectangle Submatrices with All Ones
// like 1227 but rectangle

/*
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
*/

#include <bits/stdc++.h>
using namespace std;

// dp[i][j] =x  : x*x is the maximum rectangle can perform

int countRectangles(vector<vector<int>> &a)
{
    // if(a==null || a.length==0)
    //     return 0;

    // normal case
    int m = a.size();
    int n = a[0].size();
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
                continue;
            if (a[i][j] == 1)
            {
                int tmp = 1;
                if (a[i - 1][j] > 0)
                    tmp += a[i - 1][j];
                if (a[i][j - 1] > 0)
                    tmp += a[i][j - 1];

                if (a[i - 1][j] > 0 && a[i][j - 1] > 0)
                    tmp += min(min(a[i - 1][j], a[i][j - 1]), a[i - 1][j - 1]) + 1;

                a[i][j] = tmp;
            }

            res += a[i][j];
        }
    }

    for (auto i : a)
    {

        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return res;
}
int main()
{
    vector<vector<int>> a = {
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 1, 0}};
    int res = countRectangles(a);
    cout << res << endl;
    return 0;
}

/**
 * =================================================================================================
 * 2536. Increment Submatrices by One
 * =================================================================================================
 */

// https://leetcode.com/problems/increment-submatrices-by-one/solutions/7347235/solution-by-la_castille-yqjk/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < queries.size(); ++i)
    {
        int rowStart = queries[i][0], rowEnd = queries[i][2];
        int colStart = queries[i][1], colEnd = queries[i][3];

        res[rowStart][colStart]++;
        if (colEnd + 1 < n)
            res[rowStart][colEnd + 1]--;

        if (rowEnd + 1 < n)
            res[rowEnd + 1][colStart]--;
        if (rowEnd + 1 < n && colEnd + 1 < n)
            res[rowEnd + 1][colEnd + 1]++;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i > 0)
                res[i][j] += res[i - 1][j];
            if (j > 0)
                res[i][j] += res[i][j - 1];
            if (i > 0 && j > 0)
                res[i][j] -= res[i - 1][j - 1];
        }

    return res;
}

int main()
{
    return 0;
}

/**
 * =================================================================================================
 * 3494. Find the Minimum Amount of Time to Brew Potions
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 3693. Climbing Stairs II
 * =================================================================================================
 */

#include <bits/stdc++.h>
using namespace std;

// 3693. Climbing Stairs

int climbStairs(int n, vector<int>& cost) {
    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3 && i - j >= 0; ++j)
            dp[i] = min(dp[i], dp[i - j] + cost[i - 1] + j * j);
    }
    return dp[n];
}
