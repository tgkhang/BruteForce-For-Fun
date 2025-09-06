/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solve(vector<int> &a)
{
    vector<vector<int>> res;
    int n = a.size();

    if (n < 3)
        return res;

    sort(a.begin(), a.end());

    for (size_t i = 0; i < n - 2; ++i)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue; // Skip duplicates for 'i'

        int target = 0 - a[i];

        int l = i + 1, r = n - 1;

        while (l < r)
        {
            int sum = a[l] + a[r];
            if (sum < target)
            {
                l++;
                // Eliminates all pairs (current_l, anything)
            }
            else if (sum > target)
            {
                r++;
                // eliminate pairs (anything, current_r)
            }
            else
            {
                res.push_back({a[i], a[l], a[r]});

                while (l < r && a[l] == a[l + 1])
                    l++;
                while (l < r && a[r] == a[r - 1])
                    r--;

                l++, r--;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = solve(a);

    for (const auto &triplet : res)
    {
        cout << "[";
        for (const auto &num : triplet)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
