// if first and the last character of the string are equal,
//  or no 2 adjacent characters are equal, then the answer will be score of the original string.
// Else the answer will be score of the original string + 1 .
// O(n)

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int t = 1;
    bool flag = false;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] != s[i - 1])
        t++;
      else
        flag = true;
    }

    if (s[0] == s[s.length() - 1] || !flag)
      cout << t;
    else
      cout << t + 1;

    cout << endl;
  }
  return 0;
}