/*
Problem: Find the maximum sum of a contiguous subarray using divide and conquer.
input
8
-2 -3 4 -1 -2 1 5 -3
output:
4 -1 -2 1 5
7
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;
int n;

tuple<int, int, int> solve(const vector<int> &a, int l, int r) {
    if (l == r) return make_tuple(a[l], l, r);
    int m = (l + r) / 2;
    auto [maxL, l1, r1] = solve(a, l, m);
    auto [maxR, l2, r2] = solve(a, m + 1, r);

    // Find max crossing sum
    int left_sum = INT_MIN, sum = 0, left_idx = m;
    for (int i = m; i >= l; --i) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_idx = i;
        }
    }
    int right_sum = INT_MIN; sum = 0; int right_idx = m + 1;
    for (int i = m + 1; i <= r; ++i) {
        sum += a[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_idx = i;
        }
    }
    int cross_sum = left_sum + right_sum;
    // Compare three cases
    // left max, right max, and CROSS TWO ARRAY MAX
    if (maxL >= maxR && maxL >= cross_sum)
        return make_tuple(maxL, l1, r1);
    else if (maxR >= maxL && maxR >= cross_sum)
        return make_tuple(maxR, l2, r2);
    else
        return make_tuple(cross_sum, left_idx, right_idx);
}


int main() 
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto [max_sum, start_idx, end_idx] = solve(a, 0, n - 1);
    // Print subarray
    for (int i = start_idx; i <= end_idx; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << max_sum << endl;
    return 0;
}