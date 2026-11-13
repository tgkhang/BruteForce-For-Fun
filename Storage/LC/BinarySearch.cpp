#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 4. Median of Two Sorted Arrays
 * =================================================================================================
 */

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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // o(log(n+m))-> quickselection
    // but not :) can merge, it more easy
    vector<int> tmp = merge(nums1, nums2);

    int n = nums1.size();
    int m = nums2.size();

    return ((double)(tmp[(m + n - 1) / 2] + tmp[(m + n) / 2])) / 2;
}

vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int n = nums1.size(), m = nums2.size();

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            res.push_back(nums1[i]);
            i++;
        } else {
            res.push_back(nums2[j]);
            j++;
        }
    }

    if (i == n) {
        while (j < m) {
            res.push_back(nums2[j]);
            j++;
        }
    }

    if (j == m) {
        while (i < n) {
            res.push_back(nums1[i]);
            i++;
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2}, b = {3, 4};
    cout << findMedianSortedArrays(a, b);
    return 0;
}

/**
 * =================================================================================================
 * 3453. Separate Squares I
 * =================================================================================================
 */

class Solution {
   public:
    double separateSquares(vector<vector<int>>& squares) {
        // Find the minimum and maximum y-coordinates
        double minY = squares[0][1];
        double maxY = squares[0][1] + squares[0][2];
        for (auto& square : squares) {
            double bottom = square[1];
            double top = square[1] + square[2];
            minY = min(minY, bottom);
            maxY = max(maxY, top);
        }

        // Binary search for the dividing line
        double left = minY;
        double right = maxY;
        double mid = (left + right) / 2.0;
        double prevMid = left;
        const double epsilon = 1e-5;  // 0.00001;

        while (abs(prevMid - mid) >= epsilon) {
            double areaAbove = 0.0;
            double areaBelow = 0.0;

            for (auto& square : squares) {
                double bottom = square[1];
                double top = square[1] + square[2];
                double side = square[2];
                double squareArea = side * side;

                if (top <= mid) {
                    // Entire square is below the line
                    areaBelow += squareArea;
                } else if (bottom >= mid) {
                    // Entire square is above the line
                    areaAbove += squareArea;
                } else {
                    // Square is cut by the line
                    double heightBelow = mid - bottom;
                    double heightAbove = top - mid;
                    areaBelow += side * heightBelow;
                    areaAbove += side * heightAbove;
                }
            }

            // Adjust search boundaries
            if (areaAbove > areaBelow)
                left = mid;
            else
                right = mid;

            prevMid = mid;
            mid = (left + right) / 2.0;
        }

        return mid;
    }
};
