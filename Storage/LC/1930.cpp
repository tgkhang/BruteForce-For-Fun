#include <bits/stdc++.h>
using namespace std;
int countPalindromicSubsequence(string s)
{
    int n = s.length();
    int res = 0;

    for (char c = 'a'; c <= 'z'; ++c)
    {
        int first = -1, last = -1;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == c)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        // has middle -> has palindrome
        if (first != -1 && last > first)
        {
            unordered_set<char> t;
            for (int i = first + 1; i < last; ++i)
                t.insert(s[i]);
            res += t.size();
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << countPalindromicSubsequence(s) << endl;
    return 0;
}