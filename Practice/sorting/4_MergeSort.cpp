#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> t1(n1), t2(n2);

    for (int i = 0; i < n1; ++i)
        t1[i] = a[l + i];

    for (int i = 0; i < n2; ++i)
        t2[i] = a[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // main
    while ((i < n1) && (j < n2))
    {
        if (t1[i] < t2[j])
        {
            a[k++] = t1[i++];
        }
        else
        {
            a[k++] = t2[j++];
        }
    }
    // remian

    while (i < n1)
        a[k++] = t1[i++];

    while (j < n2)
        a[k++] = t2[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    // Merge Sort function
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}