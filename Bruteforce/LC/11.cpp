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