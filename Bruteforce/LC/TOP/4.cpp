/*
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // o(log(n+m))-> quickselection
    // but not :) can merge, it more easy
    vector<int> tmp = merge(nums1, nums2);

    int n = nums1.size();
    int m = nums2.size();

    return ((double)(tmp[(m + n - 1) / 2] + tmp[(m + n) / 2])) / 2;
}

vector<int> merge(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    int n = nums1.size(), m = nums2.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
        }
        else
        {
            res.push_back(nums2[j]);
            j++;
        }
    }

    if (i == n)
    {
        while (j < m)
        {
            res.push_back(nums2[j]);
            j++;
        }
    }

    if (j == m)
    {
        while (i < n)
        {
            res.push_back(nums1[i]);
            i++;
        }
    }

    return res;
}

int main()
{

    vector<int> a = {1, 2}, b = {3, 4};
    cout << findMedianSortedArrays(a, b);
    return 0;
}