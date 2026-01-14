#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int numSub(string s)
{
    vector<int> tmp;

    long long t = s[0] == '0' ? 0 : 1;
    for (auto i = 1; i < s.size(); ++i)
    {
        if (s[i] == '1')
            t++;
        else
        {
            if (t > 0)
                tmp.push_back(t);
            t = 0;
        }
    }

    if (t > 0)
        tmp.push_back(t);

    long long res = 0;
    for (long long n : tmp)
        res = (res + n * (n + 1) / 2) % MOD;

    // caculate base on 2^n?
    return res;
}

int main()
{
    string s = "0110111";
    cout << numSub(s) << endl;
    return 0;
}


// sum 1+2+...+n = n(n+1)/2
int numSub1(string s)
{
    const int MOD = 1e9 + 7;
    long long res = 0;
    int count = 0;

    for (char c : s)
    {
        if (c == '1')
        {
            count++;
            res = (res + count) % MOD;
        }
        else
        {
            count = 0;
        }
    }

    return res;
}