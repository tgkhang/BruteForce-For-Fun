#include <bits/stdc++.h>
using namespace std;

/*

    int res = a[0], cur = a[0];
    for (int i = 1; i < a.size(); ++i) {

        cur = max(a[i], cur * a[i]);
        res = max(res, cur);
    }
    return res;

    not work; Kadane's algorithm works for maximum/minimum sum because:
    - A negative number always makes a sum smaller
    - We can simply "restart" when the running sum goes negative

    But with products, the rules are different:
    - A negative number can become positive when multiplied by another negative
    - Zero resets everything
*/

int maxProduct(vector<int> &a)
{
    int res = a[0];
    int curMax = a[0];
    int curMin = a[0]; // Track minimum too!

    for (int i = 1; i < a.size(); i++)
    {
        // When multiplying by negative, max and min swap!
        if (a[i] < 0)
        {
            swap(curMax, curMin);
        }

        curMax = max(a[i], curMax * a[i]);
        curMin = min(a[i], curMin * a[i]);

        res = max(res, curMax);
    }
    return res;
}

int main()
{
    return 0;
}