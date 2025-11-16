#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> lastIndex; // Map to store the last seen index of each character
    int res = 0;
    int l = 0; // Left pointer of the sliding window

    for (int r = 0; r < s.length(); r++)
    { // r is the right pointer of the sliding window
        char currentChar = s[r];

        // If we have seen the character before, move the left pointer
        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= l)
        {
            // Move the left pointer to one past the previous index of the current character
            l = lastIndex[currentChar] + 1;
        }

        // Update the last seen index of the current character
        lastIndex[currentChar] = r;

        // Update the result with the size of the current window
        res = max(res, r - l + 1);
    }

    return res;
}

int main()
{
    return 0;
}