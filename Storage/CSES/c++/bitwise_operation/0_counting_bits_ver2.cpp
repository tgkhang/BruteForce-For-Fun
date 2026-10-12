// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main(){

// 	ll n;
// 	cin>>n;

// 	ll res=0;
// 	for(int i=1;i<=n;++i)
// 	{
// 		res+=__builtin_popcount(i);
// 	}
// 	cout<<res;

// 	return 0;
// }

#include <bit>  // Required for std::popcount
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll res = 0;
    for (unsigned int i = 1; i <= n; ++i) {
        int ones = popcount(i);
        res += ones;
    }
    cout << res;
    return 0;
}
