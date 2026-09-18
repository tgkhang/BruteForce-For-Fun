#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// limit 10^12
// how to know how many prime in this area to build an array
// use the prime number theorem to estimate the number of primes less than or equal to n, which is approximately n / log(n). For n = 10^12, this gives us an estimate of around 37,607,912 primes
// to be safe, we can build an array of size 40 million to store all the primes up to 10^12.
const ll BASE_LIMIT = 2000000;


ll nextPrime(ll n){
    if (n < 2) return 2;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    buildBasePrimes();

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << nextPrime(n) << endl;
    }
    return 0;
}
