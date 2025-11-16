
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(n^3) solution
int MaxContSubSum3(int a[], int n)
{
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int curSum = 0;
            for (int k = i; k <= j; ++k)
            {
                curSum += a[k]; // basic operation
            }
            if (curSum > res)
                res = curSum;
        }
    }
    return res;
}

// O(n^2) solution
int MaxContSubSum2(int a[], int n)
{
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        int curSum = 0;
        for (int j = i; j < n; ++j)
        {
            curSum += a[j];
            if (curSum > res) // basic operation
                res = curSum;
        }
    }

    return res;
}

// O(n) solution using Kadane's algorithmint
int MaxContSubSum(int a[], int n)
{
    int res = 0;
    int curSum = 0;
    for (int i = 0; i < n; ++i)
    {
        curSum += a[i]; // basic operation
        if (curSum < 0)
            curSum = 0;
        if (curSum > res)
            res = curSum;
    }
    return res;
}

int main()
{
    int a[] = {1, 2, -2, 3, 22, -1, 4, 5, -3, 6, 7, 8, -9, 19, 20};
    int n = sizeof(a) / sizeof(a[0]); // OH WTF

    int res = MaxContSubSum(a, n);
    cout << "Maximum contiguous subsequence sum is: " << res << endl;
    return 0;
}