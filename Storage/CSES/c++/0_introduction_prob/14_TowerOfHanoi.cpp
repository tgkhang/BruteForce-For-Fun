#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
vector<pair<int, int>> res;

void hntower(int i, int start, int des, int mid)
{
    if (i == 1)
    {
        // cout << start << " " << des << endl;
        res.push_back(make_pair(start, des));
        return;
    }

    hntower(i - 1, start, mid, des);
    // cout << start << " " << des << endl;
    res.push_back(make_pair(start, des));
    hntower(i - 1, mid, des, start);
}

int main()
{
    ll n;
    cin >> n;
    hntower(n, 1, 3, 2);
    cout << res.size() << endl;
    for (auto i : res)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}