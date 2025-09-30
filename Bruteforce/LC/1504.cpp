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