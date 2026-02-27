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