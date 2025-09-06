#include <bits/stdc++.h>

using namespace std;

static bool comp(string a, string b)
{
    // return a<b; // 10 > 2
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> s;
    for (auto i : nums)
    {
        s.push_back(to_string(i));
    }

    sort(s.begin(), s.end(), comp);

    // sort(s.begin(), s.end(), [](string &a, string &b)
    //      { return a + b > b + a; });

    // edge case
    if (s[0] == "0")
        return "0";

    string res = "";
    for (auto i : s)
        res += i;

    return res;
}

int main()
{
    // vector<int> a = {3, 30, 34, 5, 9};
    vector<int> a = {10, 2};
    cout << largestNumber(a);

    return 0;
}