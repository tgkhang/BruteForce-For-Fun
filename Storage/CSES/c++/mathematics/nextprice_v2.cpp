#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// Base primes up to sqrt(max possible hi). n < 1e12 and window grows but
// stays tiny (prime gaps below 1e12 are nowhere near 1e5), so 2e6 is a safe
// margin for sqrt(1e12 + window).
const ll BASE_LIMIT = 2000000;
vector<ll> basePrimes;

void sieveBasePrimes() {
    vector<bool> composite(BASE_LIMIT + 1, false);
    for (ll i = 2; i * i <= BASE_LIMIT; ++i) {
        if (!composite[i]) {
            for (ll j = i * i; j <= BASE_LIMIT; j += i) {
                composite[j] = true;
            }
        }
    }
    for (ll i = 2; i <= BASE_LIMIT; ++i) {
        if (!composite[i]) basePrimes.push_back(i);
    }
}

// Returns the smallest prime > n using a segmented sieve, doubling the
// window until a prime turns up (defensive; in practice the first window
// always succeeds since gaps stay tiny at this scale).
ll nextPrime(ll n) {
    if (n < 2) return 2;

    ll lo = n + 1;
    ll window = 200000;

    while (true) {
        ll hi = lo + window - 1;
        ll size = hi - lo + 1;
        vector<bool> composite(size, false);

        for (ll p : basePrimes) {
            if (p * p > hi) break;
            ll start = max(p * p, ((lo + p - 1) / p) * p);
            for (ll j = start; j <= hi; j += p) {
                composite[j - lo] = true;
            }
        }

        for (ll v = lo; v <= hi; ++v) {
            if (v >= 2 && !composite[v - lo]) return v;
        }

        lo = hi + 1;
        window *= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieveBasePrimes();

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << nextPrime(n) << "\n";
    }
}
