/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    reverse(s.begin(), s.end());

    int finalIndex = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != ' ')
        {
            // space
            if (finalIndex != 0) s[finalIndex++] = ' ';
            int wordStart = finalIndex;
            int j = i;

            while (j < n && s[j] != ' ')
            {
                s[finalIndex++] = s[j++];
            }

            // wordstart not word start -1 as wordstart start from 0 (s.begin()+0 fo ex)
            reverse(s.begin() + wordStart, s.begin() + finalIndex);
            // j is space;
            i = j;
        }
    }

    s.resize(finalIndex);
    return s;
}

int main()
{
    string s = "the sky is blue";
    s = reverseWords(s);
    cout << s;
    return 0;
}