
#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int n, m;
int d4i[] = {-1, 0, 1, 0};
int d4j[] = {0, 1, 0, -1};

void dfs(vector<vector<char>> &a, int i, int j)
{
    a[i][j] = '#';
    // cout << i << " " << j << endl;
    for (int k = 0; k < 4; ++k)
    {
        int i1 = i + d4i[k];
        int j1 = j + d4j[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == '.')
        {

            dfs(a, i1, j1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '.')
            {
                res++;
                dfs(a, i, j);
            }
        }

    cout << res;
    return 0;
}
