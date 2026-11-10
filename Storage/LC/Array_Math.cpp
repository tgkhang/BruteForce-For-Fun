#include <bits/stdc++.h>
using namespace std;

/**
 * Array_Math problems (sorted by number)
 *
 *   7. Reverse Integer
 *   11. Container With Most Water
 *   462. Minimum Moves to Equal Array Elements II
 *   1262. Greatest Sum Divisible by Three
 *   1267. Count Servers that Communicate
 *   2211. Count Collisions on a Road
 */

/**
 * =================================================================================================
 * 7. Reverse Integer
 * =================================================================================================
 */

// INT_MAX = 2147483647 (2³¹ - 1)
// INT_MIN = -214748364
int reverse(int x) {
    if (x > INT_MAX or x < INT_MIN)
        return 0;

    int n = x;
    int rev = 0;
    while (n != 0) {
        int r = n % 10;
        // already greater than or the final pos
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && r > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && r < -8))
            return 0;

        rev = rev * 10 + r;
        n = n / 10;
    }
    return rev;
}

/**
 * =================================================================================================
 * 11. Container With Most Water
 * =================================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));

        if (height[left] < height[right])
            left++;
        else
            right--;
        // height[left] < height[right] ? left++ : right--;
    }

    return maxArea;
}

int main()
{
    return 0;
}

/**
 * =================================================================================================
 * 462. Minimum Moves to Equal Array Elements II
 * =================================================================================================
 */

// this one is medium oh my god i ran dom chooose i right:))

int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int t = nums[int(n / 2)];
    int res = 0;

    for (auto i : nums)
        res += abs(i - t);
    return res;
}

/**
 * =================================================================================================
 * 1262. Greatest Sum Divisible by Three
 * =================================================================================================
 */

#include<bits/stdc++.h>
using namespace std;



    int maxSumDivThree(vector<int>& a) {
        vector<int> one, two;
        int res = 0;
        for (auto i : a) {
            res += i;
            if (i % 3 == 1) {
                one.push_back(i);
            } else if (i % 3 == 2) {
                two.push_back(i);
            }
        }

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int r = res % 3;

        if (r == 0)
            return res;

        if (r == 1) {
            // remove smallest r=1,
            int opt1 = (!one.empty()) ? one[0] : INT_MAX;
            // remove 2 smallest r=2  => 4
            int opt2 = (two.size() >= 2) ? two[0] + two[1] : INT_MAX;
            res -= min(opt1, opt2);
        } else { // r=2
            // remove smalleset r2
            int opt1 = (!two.empty()) ? two[0] : INT_MAX ;
            // remove 2 smallest r1
            int opt2 = (one.size() >= 2) ? one[0] + one[1] : INT_MAX;
            res -= min(opt1, opt2);
        }

        return res;
    }
int main()
{
    return 0;
}

/**
 * =================================================================================================
 * 1267. Count Servers that Communicate
 * =================================================================================================
 */

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }

        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1))
                    res++;
            }

        return res;
    }
};

/**
 * =================================================================================================
 * 2211. Count Collisions on a Road
 * =================================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int countCollisions(string directions)
{
    int n = directions.size();
    int left = 0, right = n - 1;

    while (left < n && directions[left] == 'L')
        left++;
    while (right >= 0 && directions[right] == 'R')
        right--;

    int collisions = 0;
    for (int i = left; i <= right; i++)
    {
        if (directions[i] != 'S')
            collisions++;
    }

    return collisions;
}

int main()
{
    return 0;
}
