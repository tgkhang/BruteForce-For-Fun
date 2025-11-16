#include <bits/stdc++.h>
using namespace std;

void minMax2(vector<int> &a, int n, int &min, int &max)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if (a[i] > max)
        {
            max = a[i];
        }
    }
}

void minMax1(vector<int> &a, int l, int r, int &min, int &max)
{
    if(l>= r-1)
    {
        if(a[l] <a[r]){
            min = a[l];
            max = a[r];
        }
        else {
            min = a[r];
            max = a[l];
        }
    }
    else
    {
        int m= (l + r) / 2;
        int min1, max1, min2, max2;
        minMax1(a, l, m, min1, max1);
        minMax1(a, m + 1, r, min2, max2);
        if (min1 < min2)
        {
            min = min1;
        }
        else
        {
            min = min2;
        }
        if (max1 > max2)
        {
            max = max1;
        }
        else
        {
            max = max2;
        }
    }
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();

    int min = a[0], max = a[0];

    minMax1(a, 0, n - 1, min, max);

    return 0;
}