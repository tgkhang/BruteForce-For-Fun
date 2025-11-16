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

double computeAngle(const Point &a, const Point &b, const Point &c)
{
    // Calculate the angle between vectors ab and ac
    double abx = b.x - a.x;
    double aby = b.y - a.y;
    double acx = c.x - a.x;
    double acy = c.y - a.y;
    double dot = abx * acx + aby * acy;
    double det = abx * acy - aby * acx;
    double angle = atan2(det, dot);
    return angle;
}

vector<Point> computeConvexHull(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return {};
    // Find the leftmost (and then bottommost) point
    int left = 0;
    for (int i = 1; i < n; ++i)
    {
        if (points[i] < points[left])
            left = i;
    }

    // Start from the leftmost point and find the convex hull
    vector<bool> used(n, false);
    vector<Point> hull;
    int p = left;
    do
    {
        hull.push_back(points[p]);
        int next = -1;
        double bestAngle = -10.0; // -pi
        for (int i = 0; i < n; ++i)
        {
            if (i == p)
                continue;
            if (used[i] && hull.size() > 1)
                continue;
            if (next == -1)
            {
                next = i;
                continue;
            }
            double angle = computeAngle(points[p], points[next], points[i]);
            if (angle < 0)
                angle += 2 * M_PI;
            if (angle > bestAngle)
            {
                bestAngle = angle;
                next = i;
            }
        }
        p = next;
        used[p] = true;
    } while (p != left);
    return hull;
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