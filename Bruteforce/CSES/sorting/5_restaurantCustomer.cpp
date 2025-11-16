#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }

    sort(a.begin(), a.end());

    int res = 1, cur = 0;
    for (auto i : a)
    {
        // if (i.second > 0)
        //     cur++;
        // else
        //     cur--;
        cur += i.second;
        if (res < cur)
            res = cur;
    }
    cout << res;
    return 0;
}