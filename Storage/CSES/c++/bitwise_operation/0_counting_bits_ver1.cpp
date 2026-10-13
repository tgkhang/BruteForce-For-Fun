#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long countOnes(ll x) 
{
    int c = 0;
    while (x > 0) {
        c += (x & 1);
        x >>= 1;
    }
    return c;
}

int main() {
    ll n, res = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        res += countOnes(i);
    }

    cout << res;
    return 0;
}