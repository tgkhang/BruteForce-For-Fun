/***
 * instead of using n^3, think diffrenet caculate how many sub arrays current a[i] contribute to as a distinct number
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];

    map<int, int> last_pos;  // Lưu vị trí xuất hiện gần nhất của mỗi giá trị
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        int prev = 0;
        if (last_pos.count(x[i])) {  // Chỉ kiểm tra xem key có tồn tại không, KHÔNG tạo phần tử mới
            prev = last_pos[x[i]];   // Lúc này chắc chắn key tồn tại, dùng [] mới an toàn
        }

        // cachs khac
        // if (last_pos.contains(x[i])) {
        //     prev = last_pos[x[i]];
        // }
        // auto it = last_pos.find(x[i]);
        // if (it != last_pos.end()) {
        //     prev = it->second;  // it->second chính là value
        // }

        // Đóng góp của phần tử x[i] vào tổng
        ans += 1LL * (i - prev) * (n - i + 1);

        // Cập nhật vị trí mới nhất
        last_pos[x[i]] = i;
    }

    cout << ans << endl;
    return 0;
}