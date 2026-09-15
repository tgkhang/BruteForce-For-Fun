#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {
        // Tổng số cách đặt 2 quân bất kỳ nC2
        long long total = k * k * (k * k - 1) / 2;
        // Số cặp tấn công nhau
        /*
        for each cell 1 knight can attack to 8 cell
        analyze 1 cel form (x,y) and (x+1,y+1) we will have (k-1)(k-2) way to place this rectangle to the square
        same for other
        Số cách: (k-1)(k-2) (vì x chạy từ 0 đến k-2, y chạy từ 0 đến k-3)
        */
        long long attack = 4 * (k - 1) * (k - 2);
        // Kết quả
        cout << total - attack << "\n";
    }

    return 0;
}
