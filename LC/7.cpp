#include <iostream>
using namespace std;

// INT_MAX = 2147483647 (2³¹ - 1)
// INT_MIN = -214748364
int reverse(int x)
{
    if (x > INT_MAX or x < INT_MIN)
        return 0;

    int n = x;
    int rev = 0;
    while (n != 0)
    {
        int r = n % 10;
        // already greater than or the final pos
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && r > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && r < -8))
            return 0;

        rev = rev * 10 + r;
        n = n / 10;
    }
    return rev;
}

int main()
{
    return 0;
}