#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

bool isValidEdge(vector<Point> &points, int i, int j)
{
    Point pi = points[i];
    Point pj = points[j];
    int n = points.size();
    int sign = 0; // To track which side all points should be on

    for (int k = 0; k < n; ++k)
    {
        if (k == i || k == j)
            continue;

        Point pk = points[k];
        long long cross = (long long)(pj.x - pi.x) * (pk.y - pi.y) - (long long)(pj.y - pi.y) * (pk.x - pi.x);

        if (cross != 0)
        { // Not collinear
            if (sign == 0)
            {
                sign = (cross > 0) ? 1 : -1;
            }
            else if ((cross > 0 && sign < 0) || (cross < 0 && sign > 0))
            {
                return false; // Found a point on the opposite side
            }
        }
    }
    return true; // All other points are on the same side, no collinear points between pi and pj
}

vector<Point> computeConvexHull(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return points;

    set<Point> hull;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (isValidEdge(points, i, j))
            {
                hull.insert(points[i]);
                hull.insert(points[j]);
            }
        }
    }
    vector<Point> convexHull(hull.begin(), hull.end());

    // ensure no 3 points are one the same line
    for (int i = 0; i < convexHull.size(); ++i)
    {
        for (int j = i + 1; j < convexHull.size(); ++j)
        {
            for (int k = j + 1; k < convexHull.size(); ++k)
            {
                Point pi = convexHull[i];
                Point pj = convexHull[j];
                Point pk = convexHull[k];

                long long cross = (long long)(pj.x - pi.x) * (pk.y - pi.y) - (long long)(pj.y - pi.y) * (pk.x - pi.x);
                if (cross == 0)
                {
                    // If they are collinear, remove the middle point
                    convexHull.erase(convexHull.begin() + j);
                    --j; // Adjust index after erasure
                    break;
                }
            }
        }
    }

    return convexHull;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> convexHull = computeConvexHull(points);

    if (convexHull.empty())
    {
        cout << "No solution";
    }
    else
    {
        sort(convexHull.begin(), convexHull.end());
        for (auto i : convexHull)
        {
            cout << i.x << " " << i.y << endl;
        }
    }

    return 0;
}