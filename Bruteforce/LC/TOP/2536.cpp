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