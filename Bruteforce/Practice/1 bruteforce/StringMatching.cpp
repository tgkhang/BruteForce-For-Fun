//best case: p[0] is not in the string s
//worst case: every charater in s is equal to p[0] or s is all p


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sequentialStringMatching1(const string &s, const string &p)
{
    int count = 0;
    int n = s.size();
    int m = p.size();

    for (int i = 0; i <= n - m; ++i)
    {
        bool match = true;
        for (int j = 0; j < m; ++j)
        {
            if (s[i + j] != p[j])// basic operation
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            count++;
        }
    }
    return count;
}

int sequentialStringMatching(const string &s, const string &p)
{
    int count = 0;
    int n = s.size();
    int m = p.size();

    for (int i = 0; i < n - m; ++i)
    {
        int j = 0;
        while (j < m && s[i + j] == p[j]) // Basic operation
        {
            j++;
        }

        if (j == n)
            count++;
    }

    return count;
}

int main()
{

    string s = "abcdeabdab";
    string p = "ab";

    int count = sequentialStringMatching(s, p);
    cout << count;
    return 0;
}