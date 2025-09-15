// maximum subarray sum
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long res = a[0], cur = 0;

    for (int i = 0; i < n; ++i)
    {
        cur += a[i];
        res = max(res, cur);

        if (cur < 0)
            cur = 0;

        // maxEnding = max(arr[i], maxEnding + arr[i]);
        // res = max(res, maxEnding);
    }
    cout << res;
    return 0;
}
