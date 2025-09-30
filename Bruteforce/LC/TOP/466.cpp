/*
PASS BUT STILL A LOW PERFORMANCE SOLUTION
Example 1:

Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
Output: 2
Example 2:

Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
Output: 1
*/

#include <bits/stdc++.h>

using namespace std;

int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
    int l1 = s1.length(), l2 = s2.length();

    int res = 0;
    int t = 0;

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < l1; ++j)
        {
            if (s1[j] == s2[t])
            {
                t++;
                // if (t == l2 - 1)
                if (t == l2)
                {
                    res++;
                    t = 0;
                }
            }
        }

    return res / n2;
}

int main()
{
    string s1 = "acb", s2 = "ab";
    int n1 = 4, n2 = 2;

    cout << getMaxRepetitions(s1, n1, s2, n2);
    return 0;
}