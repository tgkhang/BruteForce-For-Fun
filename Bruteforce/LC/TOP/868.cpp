#include <bits/stdc++.h>
using namespace std;

int binaryGap(int n)
{
    string s = "";

    int t = n;
    while (t > 0)
    {
        int r = t % 2;
        s = (char)('0' + r) + s;
        t /= 2;
    }

    // init string

    int res = 0;
    int start = -1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '1')
        {
            if (start == -1)
            {
                start = i;
            }
            else
            {
                res = max(res, i - start);
                start = i;
            }
        }
    }
    return res;
}

int main()
{
    cout << binaryGap(5);
    return 0;
}

/*
=== TYPICAL SIZES (Platform dependent) ===

COMMON 64-bit SYSTEM:
- char: 8 bits (1 byte)
- short: 16 bits (2 bytes)
- int: 32 bits (4 bytes)
- long: 64 bits (8 bytes) on Linux/Mac, 32 bits (4 bytes) on Windows
- long long: 64 bits (8 bytes)
- float: 32 bits (4 bytes)
- double: 64 bits (8 bytes)
- long double: 80/128 bits (varies by compiler)
- bool: 8 bits (1 byte, but only uses 1 bit logically)
- void*: 64 bits (8 bytes)

RANGES FOR SIGNED INTEGERS:
- char: -128 to 127
- short: -32,768 to 32,767
- int: -2,147,483,648 to 2,147,483,647
- long long: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

RANGES FOR UNSIGNED INTEGERS:
- unsigned char: 0 to 255
- unsigned short: 0 to 65,535
- unsigned int: 0 to 4,294,967,295
- unsigned long long: 0 to 18,446,744,073,709,551,615

GUARANTEED MINIMUMS (C++ Standard):
- char: at least 8 bits
- short: at least 16 bits
- int: at least 16 bits
- long: at least 32 bits
- long long: at least 64 bits

RELATIONSHIPS GUARANTEED BY STANDARD:
sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
sizeof(float) <= sizeof(double) <= sizeof(long double)
*/

int binaryGap(int n)
{
    int res = 0;
    int start = -1;

    for (int i = 0; i < 32; ++i)
    {
        if ((n >> i) & 1)
        { // Check if i-th bit is 1
            if (start != -1)
            {
                res = max(res, i - start);
            }
            start = i;
        }
    }
    return res;
}