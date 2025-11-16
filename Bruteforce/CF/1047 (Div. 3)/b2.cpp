//test claude
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        long long ans = -1;
        
        // The maximum value of a*k + b/k is achieved at the endpoints
        // or when the derivative is 0 (but k must be integer divisor)
        
        // Always check k = 1 and
        if ((a + b) % 2 == 0) {
            ans = max(ans, a + b);
        }
        // k = b
        if ((a * b + 1) % 2 == 0) {
            ans = max(ans, a * b + 1);
        }
        
        
        // If b is even, check k = 2 and k = b/2
        if (b % 2 == 0) {
            // k = 2
            long long sum1 = a * 2 + b / 2;
            if (sum1 % 2 == 0) {
                ans = max(ans, sum1);
            }
            
            // k = b/2  
            long long sum2 = a * (b / 2) + 2;
            if (sum2 % 2 == 0) {
                ans = max(ans, sum2);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}