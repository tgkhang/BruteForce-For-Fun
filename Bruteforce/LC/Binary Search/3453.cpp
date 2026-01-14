#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        // Find the minimum and maximum y-coordinates
        double minY = squares[0][1];
        double maxY = squares[0][1] + squares[0][2];
        for (auto &square : squares)
        {
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
        const double epsilon = 1e-5; // 0.00001;

        while (abs(prevMid - mid) >= epsilon)
        {
            double areaAbove = 0.0;
            double areaBelow = 0.0;

            for (auto &square : squares)
            {
                double bottom = square[1];
                double top = square[1] + square[2];
                double side = square[2];
                double squareArea = side * side;

                if (top <= mid)
                {
                    // Entire square is below the line
                    areaBelow += squareArea;
                }
                else if (bottom >= mid)
                {
                    // Entire square is above the line
                    areaAbove += squareArea;
                }
                else
                {
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