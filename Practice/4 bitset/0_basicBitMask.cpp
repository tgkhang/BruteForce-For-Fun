// let the second array sorted

#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    int mask = 10, j = 1;

    // checking if j th bit is set (1)
    if (mask >> j & 1)
    {
        // mask >> j: Shift right by j positions
        //& 1: Check if the last bit is 1
    }

    // setting jth bit to 1
    mask = mask | (1 << j);

    // Unsetting j-th bit (set to 0)
    mask = mask & ~(1 << j);
    return 0;
}