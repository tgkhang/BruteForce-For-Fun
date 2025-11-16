#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s)
{
    int res = 0, sign = 1;
    int n = s.length(), i = 0;

    // space
    while (i < n && s[i] == ' ')
        i++;

    // sign
    if (i < n)
        if (s[i] == '+' || s[i] == '-')
        {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

    // zero
    while (i < n && s[i] == '0')
        i++;

    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        // overflow
        if (res > (INT_MAX - digit) / 10)
            return (sign == 1) ? INT_MAX : INT_MIN;

        res = res * 10 + digit;
        i++;
    }
    return res * sign;
}

int main()
{
    return 0;
}