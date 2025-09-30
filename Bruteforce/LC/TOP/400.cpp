// 1-9  : 9  base case return that

// 10-99 : 90

// 100-999: 900

// 1000- 9999 : 9000
/*
9*1
90*2
900*3
9000*4
*/

#include <bits/stdc++.h>
using namespace std;

int findNthDigit(int n)
{
    // detect range
    int digit = 1, numOfNum = 9;

    while (n > digit * numOfNum)
    {
        n -= digit * numOfNum;
        digit++;
        numOfNum *= 10;
    }

    int pos = (n - 1) / digit; // n minus first number/ digit
    int remainder = (n - 1) % digit;
    int start = (digit == 1) ? 1 : pow(10, digit - 1); // startnumber

    string s = to_string(start + pos);
    return s[remainder] - '0';
}

int main()
{
    int n = 11;
    cout << findNthDigit(n);
    return 0;
}