/*
    This is a brute force solution to the Convex Hull problem.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point
{
    int x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point &other) const
    {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }
};

bool isValidEdge(vector<Point> &points, int i, int j)
{
    Point a = points[i];
    Point b = points[j];

    int n = points.size();
    int sign = 0;
    for (int k = 0; k < n; ++k)
    {
        if (k == i || k == j)
            continue;

        Point t = points[k];

        // p1(x,y) p2(x,y) p3(x,y)
        // p1p2 (p2x-p1x , p2y-p1y)
        // p1p3 (p3x-p1x , p3y-p1y)
        // cross product of p1p2 and p1p3
        // (p2x-p1x)*(p3y-p1y) - (p2y-p1y)*(p3x-p1x)

        ll cross = (ll)(b.x - a.x) * (t.y - a.y) - (b.y - a.y) * (t.x - a.x);

        if (cross != 0)
        {
            if (sign == 0)
            {
                sign = (cross > 0) ? 1 : -1;
            }
            else if ((cross > 0 && sign < 0) || (cross < 0 && sign > 0))
                return false;
        }
    }
    return true;
}

vector<Point> computeConvexHull(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return points;

    set<Point> hull;

    for (ll i = 0; i < n; ++i)
        for (ll j = i + 1; j < n; ++j)
        {
            if (isValidEdge(points, i, j))
            {
                hull.insert(points[i]);
                hull.insert(points[j]);
            }
        }

    vector<Point> convexHull(hull.begin(), hull.end());

    // ensure no 3 points are on the same line
    for (ll i = 0; i < convexHull.size(); ++i)
    {
        for (ll j = i + 1; j < convexHull.size(); ++j)
        {
            for (ll k = j + 1; k < convexHull.size(); ++k)
            {
                Point a = convexHull[i];
                Point b = convexHull[j];
                Point c = convexHull[k];

                ll cross = (ll)(b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
                if (cross == 0)
                {
                    convexHull.erase(convexHull.begin() + j);
                    --j;
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
    for (ll i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    vector<Point> convexHull = computeConvexHull(points);

    if (convexHull.empty())
    {
        cout << "No solution";
    }
    else
    {
        sort(convexHull.begin(), convexHull.end());

        for (auto i : convexHull)
            cout << i.x << " " << i.y << endl;
    }
    return 0;
}