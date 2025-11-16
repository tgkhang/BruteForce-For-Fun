#include <bits/stdc++.h>
using namespace std;

void cockTailSort(vector<int> &a)
{
    int n = a.size();
    bool swapped = true;
    int start = 0, end = n - 1;
    while (swapped)
    {

        swapped = false;
        // first iteration
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
        end--;
        swapped = false;
        // second iteration
        for (int i = end; i > start; --i)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swapped = true;
            }
        }
        start++;
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 100, 0, -1, -5};

    for (auto i : arr)
        cout << i << " ";

    cockTailSort(arr);

    cout << endl;
    for (auto i : arr)
        cout << i << " ";

    return 0;
}