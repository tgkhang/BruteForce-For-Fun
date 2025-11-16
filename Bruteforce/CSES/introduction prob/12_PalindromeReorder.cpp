#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    unordered_map<char, int> ma;
    string s;
    cin >> s;

    for (auto i : s)
    {
        ma[i]++;
    }

    int count = 0;
    char odd_char = '\0';

    for (auto i : ma)
    {
        if (i.second % 2 != 0)
        {
            count++;
            odd_char = i.first;
            if (count > 1)
            {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }

    string res = string(ma[odd_char], odd_char);
    for (auto i : ma)
    {
        if (i.second % 2 != 0)
            continue;

        int t = (i.second) / 2;
        res += string(t, i.first);
        res = string(t, i.first) + res;
    }
    cout << res;
    return 0;
}