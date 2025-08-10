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
    int total = lenX + lenY;

    // Binary search for the correct partition
    while (left <= right)
    {
        int cutX = (left + right) / 2;     // Number of elements in left part of x
        int cutY = (total + 1) / 2 - cutX; // Number of elements in left part of y

        // Get border values for both arrays
        int leftX = (cutX == 0) ? INT_MIN : x[xl + cutX - 1];
        int rightX = (cutX == lenX) ? INT_MAX : x[xl + cutX];
        int leftY = (cutY == 0) ? INT_MIN : y[yl + cutY - 1];
        int rightY = (cutY == lenY) ? INT_MAX : y[yl + cutY];

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