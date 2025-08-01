#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(const string &a, const string &b)
{
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string subStrings(const string &a, const string &b)
{ // assumes a >= b
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0)
    {
        int sub = a[i] - '0' - carry - (j >= 0 ? b[j] - '0' : 0);
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        res.push_back(sub + '0');
        i--;
        j--;
    }
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string shift(const string &a, int n)
{
    return a + string(n, '0');
}

string karatsuba(const string &x, const string &y)
{
    int n = max(x.size(), y.size());
    if (n == 1)
    {
        int prod = (x[0] - '0') * (y[0] - '0');
        return to_string(prod);
    }
    int m = n / 2;

    // eg 1234
    // x0= 34
    // x1= 12

    string x0 = x.size() > m ? x.substr(x.size() - m) : x, x1 = x.size() > m ? x.substr(0, x.size() - m) : "0";
    string y0 = y.size() > m ? y.substr(y.size() - m) : y, y1 = y.size() > m ? y.substr(0, y.size() - m) : "0";

    // remove front zerp
    while (x1.size() > 1 && x1[0] == '0')
        x1.erase(0, 1);
    while (y1.size() > 1 && y1[0] == '0')
        y1.erase(0, 1);

    string z0 = karatsuba(x0, y0);
    string z2 = karatsuba(x1, y1);

    // ad + bc= (a+b)(c+d) - (ac+bd)
    string z1 = karatsuba(addStrings(x0, x1), addStrings(y0, y1)); // (a+b)*(c+d)
    z1 = subStrings(subStrings(z1, z0), z2);                       // ad + bc

    string res = addStrings(addStrings(shift(z2, 2 * m), shift(z1, m)), z0);

    // remove leading zeros
    while (res.size() > 1 && res[0] == '0')
        res.erase(0, 1);
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    // Pad strings to make their lengths equal and a power of 2
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    cout << n << endl;
    a = string(n - a.size(), '0') + a;
    b = string(n - b.size(), '0') + b;
    cout << karatsuba(a, b) << endl;
    return 0;
}
