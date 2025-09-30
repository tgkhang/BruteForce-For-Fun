#include <bits/stdc++.h>
using namespace std;

// Partition(a, left, right)
// {
//     p = a[left];
//     i = left + 1;
//     j = right;
//     while (i <= j)
//     {
//         while (i <= j && a[i] < p)
//             i++; // Bounds check: i <= j
//         while (i <= j && a[j] > p)
//             j--; // Bounds check: i <= j
//         if (i <= j)
//         {
//             swap(a[i], a[j]);
//             i++;
//             j--;
//         }
//     }
//     swap(a[left], a[j]); // Pivot to final position
//     return j;
// }

int partition(vector<int> &a, int l, int r)
{
    int pivot = a[r];

    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

int partition2(vector<int> &a, int l, int r)
{
    int pivot = a[l];
    int i = l + 1;

    for (int j = l + 1; j <= r; ++j)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[l], a[i - 1]);
    return i - 1;
}

void quickSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int t = partition(a, l, r);
        quickSort(a, l, t - 1);
        quickSort(a, t + 1, r);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}