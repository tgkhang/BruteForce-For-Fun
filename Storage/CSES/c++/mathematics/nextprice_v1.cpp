#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (ll i = 5; i * i <= x; ++i) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

ll nextPrime(ll n) {
    if (n < 2) return 2;

    ll candidate = n + 1;
    if (candidate % 2 == 0)
        candidate++;

    while (!isPrime(candidate))

        candidate += 2;
    return candidate;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << nextPrime(n) << endl;
    }
}
