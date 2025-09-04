/*
Input: s = "babad"
Output: "bab"
*/

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    if (n == 0)
        return "";

    int start = 0;
    int maxLen =1;


    auto expandAroundCenter = [&](int left, int right)
    {
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    };


    for (int i = 0; i < n; i++)
    {

        int len1 = expandAroundCenter(i, i); //case string has the middle character 

        int len2 = expandAroundCenter(i, i + 1); // case string not has the middle character

        int len = max(len1, len2);

        if (len > maxLen)
        {
            maxLen = len;
            start = i - (maxLen - 1) / 2;
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
    string s = "babad";

    cout << longestPalindrome(s);
    return 0;
}