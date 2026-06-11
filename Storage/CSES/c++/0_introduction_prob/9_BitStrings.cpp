#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

ll pow(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    ll t = pow(x, n / 2);

    if (n % 2 == 0)
        return (t * t) % MOD;
    else
        return ((t * t) % MOD * x) % MOD;
}

int main()
{
    int n;
    cin >> n;

    cout << pow(2, n);
}