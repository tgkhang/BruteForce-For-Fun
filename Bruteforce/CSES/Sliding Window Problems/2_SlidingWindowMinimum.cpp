#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <deque>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int solve1()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for (int i = 1; i < n; ++i)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    ll res = 0, minCur = LLONG_MAX;

    for (int i = 0; i < k; ++i)
    {
        minCur = min(minCur, arr[i]);
    }

    res = minCur;
    // cout << res << " ";
    for (int i = k; i < n; ++i)
    {
        if (arr[i - k] == minCur)
        {
            minCur = LLONG_MAX;
            for (int j = i - k + 1; j <= i; ++j)
                minCur = min(minCur, arr[j]);
        }
        else
        {
            minCur = min(minCur, arr[i]);
        }

        res ^= minCur;
    }
    cout << res;
}

int main()
{
    // The deque only contains elements that could potentially become minimums in future windows
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for (int i = 1; i < n; ++i)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    deque<ll> dq;

    ll res = 0;

    for (int i = 0; i < n; ++i)
    {

        // keep the first element is the smallest

        // remove element not in window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();

        dq.push_back(i);

        // enough element to form a window
        if (i >= k - 1)
        {
            res ^= arr[dq.front()];
        }
    }

    cout << res;

    return 0;
}