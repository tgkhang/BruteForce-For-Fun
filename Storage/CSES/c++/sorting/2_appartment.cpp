#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int a, int b, int k)
{
    if (b >= a - k && b <= a + k)
        return true;
    return false;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    for (int i = 0; i < m; ++i)
        cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int res = 0;

    int t = 0;

    for (int i = 0; i < n && t < m; ++i)
    {
        while (t < m && y[t] < x[i] - k)
        {
            t++;
        }

        if (t < m && y[t] <= x[i] + k)
        {
            res++;
            t++;
        }
    }

    cout << res;

    return 0;
}