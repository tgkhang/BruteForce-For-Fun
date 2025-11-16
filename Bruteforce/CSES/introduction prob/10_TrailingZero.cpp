// trailing zero of n!

/*
traling zero coming factor of 10 = 2*5
usually seeing that factor of 2 will be more than 5
so we count number of 5 appear

n=25
i = 5: 25/5 = 5 → numbers {5, 10, 15, 20, 25} each contribute 1 factor of 5
i = 25: 25/25 = 1 → number {25} contributes 1 additional factor of 5 (since 25 = 5²)
i = 125: 25/125 = 0 → no numbers

25 = 5² contains TWO factors of 5, not just one!
i = 5: 25/5 = 5 counts ALL multiples of 5: {5, 10, 15, 20, 25}
i = 25: 25/25 = 1 counts multiples of 25: {25}

5 = 5¹ → contributes 1 factor of 5
10 = 2 × 5 → contributes 1 factor of 5
15 = 3 × 5 → contributes 1 factor of 5
20 = 4 × 5 → contributes 1 factor of 5
25 = 5 x 5 → count the second, not the first
*/
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;

    // for (ll i = 10; i <= n; i *= 10)
    // {
    //     ans += n / i;
    // }
    for (ll i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans;

    return 0;
}

/*

i = 10: n/10 counts numbers divisible by 10 (like 10, 20, 30...)
i = 100: n/100 counts numbers divisible by 100 (like 100, 200, 300...)
i = 1000: n/1000 counts numbers divisible by 1000 (like 1000, 2000...
Example: n = 25= 1*...10*20*
Numbers divisible by 10: 10, 20 → contributes 2 trailing zeros
Numbers divisible by 100: none → contributes 0
Total: 2 trailing zeros
*/