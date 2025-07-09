/*
Convex Hull using Brute Force Approach O(n^3)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

// Function to find the cross product of vectors (p1-p0) and (p2-p0)
// Returns positive if counter-clockwise, negative if clockwise, 0 if collinear
ll crossProduct(Point p0, Point p1, Point p2)
{
    return (ll)(p1.x - p0.x) * (p2.y - p0.y) - (ll)(p1.y - p0.y) * (p2.x - p0.x);
}

// Brute force convex hull algorithm - O(n^3)
vector<pair<Point, Point>> bruteForceConvexHull(vector<Point> &points)
{
    int n = points.size();
    vector<pair<Point, Point>> convexHullEdges;

    // For each pair of points (pi, pj)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Point pi = points[i];
            Point pj = points[j];

            bool validEdge = true;
            int sign = 0; // To track which side all points should be on

            // Check all other points to see if they lie on the same side
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;

                Point pk = points[k];
                ll cross = crossProduct(pi, pj, pk);

                if (cross != 0)
                { // Not collinear
                    if (sign == 0)
                    {
                        sign = (cross > 0) ? 1 : -1;
                    }
                    else if ((cross > 0 && sign < 0) || (cross < 0 && sign > 0))
                    {
                        validEdge = false;
                        break;
                    }
                }
            }

            // If all points lie on the same side, this edge is part of convex hull
            if (validEdge)
            {
                convexHullEdges.push_back({pi, pj});
            }
        }
    }

    return convexHullEdges;
}

// Function to print the convex hull edges
void printConvexHull(const vector<pair<Point, Point>> &edges)
{
    cout << "Convex Hull Edges:" << endl;
    for (const auto &edge : edges)
    {
        cout << "(" << edge.first.x << ", " << edge.first.y << ") -> ";
        cout << "(" << edge.second.x << ", " << edge.second.y << ")" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter " << n << " points (x y):" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    // Find convex hull using brute force approach
    vector<pair<Point, Point>> convexHullEdges = bruteForceConvexHull(points);

    // Print the result
    printConvexHull(convexHullEdges);

    cout << "\nTotal edges in convex hull: " << convexHullEdges.size() << endl;

    return 0;
}
