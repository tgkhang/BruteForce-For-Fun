#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void bubbleSortOptimized(vector<int> &a)
{
    int n = a.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // No swaps means the array is sorted
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 100, 0, -1, -5};

    for (auto i : arr)
        cout << i << " ";
    bubbleSort(arr);

    cout << endl;
    for (auto i : arr)
        cout << i << " ";

    return 0;
}