#include <bits/stdc++.h>

using namespace std;

/*

void wiggleSort(vector<int> &a)
{
    vector<int> res;

    sort(a.begin(), a.end());

    int t = 0, n = a.size(), l = 0, r = n - 1;

    while (t < n)
    {
        res.push_back(a[l++]);
        t++;

        if (t == n)
            break;
        res.push_back(a[r--]);
        t++;
    }

    a = res;
}
 has equal case so wrong
*/

//[4, 5, 5, 6] wrong
void wiggleSortWrong(vector<int> &a)
{
    vector<int> res;

    sort(a.begin(), a.end());

    int n = a.size();
    int t;
    if (n % 2 == 0)
        t = n / 2;
    else
        t = n / 2 + 1;

    int t1 = 0, t2 = t, count = 0;
    while (count < n)
    {
        res.push_back(a[t1++]);
        count++;

        if (count == n)
            break;
        res.push_back(a[t2++]);
        count++;
    }
    a = res;
}

void wiggleSort(vector<int> &a)
{
    int n = a.size();
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    int mid = (n - 1) / 2;

    int left = mid;
    int right = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = sorted[left--];
        }
        else
        {
            a[i] = sorted[right--];
        }
    }
}

int main()
{
    return 0;
}