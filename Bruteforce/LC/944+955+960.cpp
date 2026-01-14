#include <bits/stdc++.h>
using namespace std;

int minDeletionSize944(vector<string> &strs)
{

    int r = strs.size();
    int c = strs[0].length();

    int res = 0;
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r - 1; ++j)
        {
            if (strs[j][i] > strs[j + 1][i])
            {
                res++;
                break;
            }
        }
    }
    return res;
}

int minDeletionSize995(vector<string> &strs)
{
    int r = strs.size();
    int c = strs[0].length();
    int res = 0;

    // sorted[i] = true: strs[i] đã < strs[i+1] khi duyệt đến cột hiện tại
    vector<bool> sorted(r - 1, false);

    for (int i = 0; i < c; ++i)
    {
        bool needDelete = false;        // do we need to delete this column?
        for (int j = 0; j < r - 1; ++j) // hàng
        {
            if (!sorted[j] && strs[j][i] > strs[j + 1][i])
            {
                needDelete = true;
                break;
            }
        }
        if (needDelete)
            res++;
        else // cột này không bị xóa
        {
            for (int row = 0; row < r - 1; ++row)
            {
                if (strs[row][i] < strs[row + 1][i])
                    sorted[row] = true;
            }
        }
    }

    return res;
}

// 960
int minDeletionSize960(vector<string> &strs)
{
    int r = strs.size();
    int c = strs[0].length();

    vector<int> tmp(c, 1);

    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            bool canPlaceAfter = true;
            for (int k = 0; k < r; ++k)
            {

                if (strs[k][i] < strs[k][j])
                {
                    canPlaceAfter = false;
                    break;
                }
            }

            if (canPlaceAfter)

                tmp[i] = max(tmp[j] + 1, tmp[i]);
        }
    }

    int res = *max_element(tmp.begin(), tmp.end());
    return c - res;
}

int main()
{
}