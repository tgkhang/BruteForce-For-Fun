#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

// Helper: Compute the bit length of a number
int bit_length(uint64_t x)
{
    if (x == 0)
        return 0;
    int len = 0;
    while (x)
    {
        ++len;
        x >>= 1;
    }
    return len;
}

// Karatsuba multiply for two non-negative integers
uint64_t multiply(uint64_t x, uint64_t y)
{
    int n = max(bit_length(x), bit_length(y));
    // Threshold for switching to schoolbook multiplication
    const int ALPHA = 16;
    if (n <= ALPHA)
        return x * y;

    // Pad n to even
    int half = n / 2;
    uint64_t mask = (1ULL << half) - 1;

    // high and low parts
    uint64_t xL = x >> half;
    uint64_t xR = x & mask;
    uint64_t yL = y >> half;
    uint64_t yR = y & mask;

    uint64_t p = multiply(xL, yL);
    uint64_t q = multiply(xR, yR);
    uint64_t r = multiply(xL + xR, yL + yR);

    return (p << (2 * half)) + ((r - p - q) << half) + q;
}

int main()
{
    uint64_t a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}
