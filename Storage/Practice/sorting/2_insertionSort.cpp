#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}
// you can use the sentinel technique to optimize the insertion sort
// by adding a sentinel value at the beginning of the array
void insertionSortOptimized(vector<int> &a)
{
    int n = a.size();
    a.insert(a.begin(), INT_MIN); // Add sentinel at the beginning
    for (int i = 2; i <= n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    a.erase(a.begin()); // Remove the sentinel
}
int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 100, 0, -1, -5};

    for (auto i : arr)
        cout << i << " ";
    insertionSort(arr);

    cout << endl;
    for (auto i : arr)
        cout << i << " ";

    return 0;
}