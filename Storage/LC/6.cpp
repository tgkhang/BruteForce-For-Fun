// zig zag conversion
/*
+8
+6+8
+4+8
+2+8
+8
n=5
p     h
a   s i
y  i  r
p l   i g
a     n



 n=4
+6
+4+6
+2+6
+6

n=3
+4
+2+4
+4


n=2
+2
+2

n=1
+1


*/
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

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int n = s.length();
    string res = "";

    int i = 0;
    int cycleLen = 2 * numRows - 2;

    // first row
    for (int i = 0; i < n; i += cycleLen)
    {
        res += s[i];
    }

    // mid
    for (int k = 1; k < numRows - 1; k++)
    {
        // i = k;
        // int t1 = t - 2 * k;
        // while (i < n) {
        //     res += s[i];
        //     i += t1;
        //     res + s[i];
        //     i += t;
        // }
        for (int i = k; i < n; i += cycleLen)
        {
            res += s[i];
            int next = i + cycleLen - 2 * k;
            if (next < n)
            {
                res += s[next];
            }
        }
    }

    // last row

    for (int i = numRows - 1; i < n; i += cycleLen)
    {
        res += s[i];
    }
    return res;
}

int main()
{

    return 0;
}