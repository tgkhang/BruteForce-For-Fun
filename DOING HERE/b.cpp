#include <iostream>
#include <climits>
using namespace std;

int findMedian(int x[], int y[], int xl, int xr, int yl, int yr)
{
    // Calculate the lengths of the subarrays
    int lenX = xr - xl + 1;
    int lenY = yr - yl + 1;

    // Always make sure lenX <= lenY for easier handling
    if (lenX > lenY)
    {
        return findMedian(y, x, yl, yr, xl, xr);
    }

    int left = 0, right = lenX;
    // total: total number of elements in both arrays
    int total = lenX + lenY;

    // Binary search for the correct partition
    while (left <= right)
    {
        // cutX: number of elements from x on the left side of the partition
        int cutX = (left + right) / 2;
        // cutY: number of elements from y on the left side of the partition
        // The sum of cutX and cutY is always half of total (or half+1 if odd)
        int cutY = (total + 1) / 2 - cutX;

        // leftX: largest value on the left side of x's partition
        int leftX;
        if (cutX == 0)
        {
            // If no elements on the left, set to smallest possible integer
            leftX = INT_MIN;
        }
        else
        {
            // Otherwise, get the last element on the left side
            leftX = x[xl + cutX - 1];
        }

        // rightX: smallest value on the right side of x's partition
        int rightX;
        if (cutX == lenX)
        {
            // If no elements on the right, set to largest possible integer
            rightX = INT_MAX;
        }
        else
        {
            // Otherwise, get the first element on the right side
            rightX = x[xl + cutX];
        }

        // leftY: largest value on the left side of y's partition
        int leftY;
        if (cutY == 0)
        {
            leftY = INT_MIN;
        }
        else
        {
            leftY = y[yl + cutY - 1];
        }

        // rightY: smallest value on the right side of y's partition
        int rightY;
        if (cutY == lenY)
        {
            rightY = INT_MAX;
        }
        else
        {
            rightY = y[yl + cutY];
        }

        // Check if partition is valid
        if (leftX <= rightY && leftY <= rightX)
        {
            // Odd total length: median is max of left borders
            if (total % 2 == 1)
            {
                return max(leftX, leftY);
            }
            // Even total length: median is average of max left and min right
            else
            {
                return (max(leftX, leftY) + min(rightX, rightY)) / 2;
            }
        }
        // If leftX is too big, move cutX left
        else if (leftX > rightY)
        {
            right = cutX - 1;
        }
        // If leftY is too big, move cutX right
        else
        {
            left = cutX + 1;
        }
    }

    // If input is invalid, return -1
    return -1;
}

// Test function
int main()
{
    int x[] = {1, 3, 8, 9, 15};
    int y[] = {7, 11, 18, 19, 21, 25};

    int m = sizeof(x) / sizeof(x[0]);
    int n = sizeof(y) / sizeof(y[0]);

    int median = findMedian(x, y, 0, m - 1, 0, n - 1);
    cout << "Median: " << median << endl;

    return 0;
}