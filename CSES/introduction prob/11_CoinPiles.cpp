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

void solve()
{
    int a, b;
    cin >> a >> b;
    // Neither pile can have more than twice the coins of the other
    if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}