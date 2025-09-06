#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;
    for (auto i : num)
    {
        while (!st.empty() && i < st.top() && k > 0)
        {
            k--;
            st.pop();
        }
        st.push(i);
    }

    while (k != 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    // find
    // find first not of
    // find first of
    // find last not of
    // find last of
    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos)
        res = "0";
    else
        res = res.substr(pos);

    return res;
}

string removeKdigits1(string num, int k)
{
    string result = "";

    for (char digit : num)
    {
        while (!result.empty() && result.back() > digit && k > 0)
        {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }

    while (k > 0 && !result.empty())
    {
        result.pop_back();
        k--;
    }

    size_t pos = result.find_first_not_of('0');
    if (pos == string::npos)
        return "0";

    result = result.substr(pos);
    return result.empty() ? "0" : result;
}

int main()
{
    string num = "1432219";
    int k = 3;

    cout << removeKdigits(num, k);
    return 0;
}