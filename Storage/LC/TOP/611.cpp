

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangleNumberBruteForce(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // Only need to check this condition since array is sorted
                if (nums[i] + nums[j] > nums[k])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    // chose k and right as 2 valid number
    for (int k = 2; k < n; k++)
    {
        int left = 0, right = k - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > nums[k])
            {
                // All pairs (left, left+1), (left, left+2), ..., (left, right)
                count += (right - left);
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}