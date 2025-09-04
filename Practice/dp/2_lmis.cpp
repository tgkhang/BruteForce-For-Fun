// longest monotonically increasing subsequence (dynamic programming approach)
/*
input:
5  
8 9 12 10 11
ouput:
8 9 10 11
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int maxLength, pos;

void printResult(int i, vector<int> &dp, vector<int> &parent)
{
    if (i < 0)
        return;

    
    printResult(parent[i], dp, parent);
    cout << v[i] << " ";
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 0)
        return 0;

    v.resize(n);
    vector<int> parent(n, -1);
    vector<int> dp(n, 1);
    maxLength = 1, pos = 0;

    for (size_t i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    for (size_t i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }

            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                pos = i;
            }
        }
    }

    printResult(pos, dp, parent);

    return 0;
}