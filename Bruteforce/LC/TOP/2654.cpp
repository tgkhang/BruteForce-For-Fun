#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minOperations(vector<int> &nums)
{
    int n = nums.size(), minLen = INT_MAX;

    int countOnes = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 1)
            countOnes++;
    }
    if (countOnes > 0)
        return n - countOnes;

    for (int i = 0; i < n; ++i)
    {

        int tmp = nums[i];
        for (int j = i + 1; j < n; ++j)
        {
            tmp = __gcd(tmp, nums[j]);

            if (tmp == 1)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }

    if (minLen == INT_MAX)
        return -1;
    return minLen + n - 2;
}

int main()
{
    return 0;
}