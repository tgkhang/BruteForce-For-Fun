#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Helper: Remove leading zeros from a string
string remove_leading_zeros(const string &num)
{
    size_t start = num.find_first_not_of('0');
    return (start == string::npos) ? "0" : num.substr(start);
}

// Helper: Add two numbers as strings
string add(const string &a, const string &b)
{
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    reverse(result.begin(), result.end());
    return remove_leading_zeros(result);
}

// Helper: Subtract two numbers as strings (assumes a >= b)
string subtract(const string &a, const string &b)
{
    string result;
    int borrow = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0)
    {
        int digit = borrow + (i >= 0 ? a[i--] - '0' : 0);
        if (j >= 0)
            digit -= (b[j--] - '0');
        if (digit < 0)
        {
            digit += 10;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(digit + '0');
    }
    reverse(result.begin(), result.end());
    return remove_leading_zeros(result);
}

// Helper: Multiply a number by 10^n (append zeros)
string shift_left(const string &num, int n)
{
    if (num == "0")
        return num;
    return num + string(n, '0');
}

// Helper: Schoolbook multiplication for small numbers
string schoolbook_multiply(const string &x, const string &y)
{
    vector<int> result(x.size() + y.size(), 0);
    for (int i = x.size() - 1; i >= 0; --i)
    {
        for (int j = y.size() - 1; j >= 0; --j)
        {
            int prod = (x[i] - '0') * (y[j] - '0');
            result[i + j + 1] += prod % 10;
            result[i + j] += prod / 10 + result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    string res;
    for (int digit : result)
        res += to_string(digit);
    return remove_leading_zeros(res);
}

// Karatsuba multiplication for big numbers
string multiply(const string &x, const string &y)
{
    // Remove leading zeros
    string a = remove_leading_zeros(x);
    string b = remove_leading_zeros(y);

    // Base case
    int n = max(a.size(), b.size());
    const int ALPHA = 16;
    if (n <= ALPHA)
        return schoolbook_multiply(a, b);

    // Pad to equal length
    while (a.size() < n)
        a = "0" + a;
    while (b.size() < n)
        b = "0" + b;

    // Split into high and low parts
    int half = n / 2;
    string xL = a.substr(0, a.size() - half);
    string xR = a.substr(a.size() - half);
    string yL = b.substr(0, b.size() - half);
    string yR = b.substr(b.size() - half);

    // Recursive steps
    string p = multiply(xL, yL);                   // p = xL * yL
    string q = multiply(xR, yR);                   // q = xR * yR
    string r = multiply(add(xL, xR), add(yL, yR)); // r = (xL + xR) * (yL + yR)

    // Compute middle term: r - p - q
    string middle = subtract(subtract(r, p), q);

    // Combine: p * 10^(2*half) + (r - p - q) * 10^half + q
    return add(add(shift_left(p, 2 * half), shift_left(middle, half)), q);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}