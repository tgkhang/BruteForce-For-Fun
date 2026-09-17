#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll x){
    if(x<=1)return false;
    if(x<=3)return true;
    if(x%2==0 || x%3==0) return false;
    for (ll i=5;i*i<=x; ++i)
        {
            
        }
}

int main()
{
    return 0;
}


    // Check factors up to sqrt(n)
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
           return false;
        }
    }
    return true;
}

// Function to find the next prime strictly greater than n
long long nextPrime(long long n) {
    if (n < 2) return 2;

    long long candidate = n + 1;
    
    // If the candidate is even, move to the next odd number
    if (candidate % 2 == 0) {
        candidate++;
    }

    // Test subsequent odd numbers
    while (!isPrime(candidate)) {
        candidate += 2;
    }
    
    return candidate;
}

int main() {
    long long n = 1000000000000LL; // 10^12
    std::cout << "Next prime after " << n << " is " << nextPrime(n) << std::endl;
    return 0;
}
