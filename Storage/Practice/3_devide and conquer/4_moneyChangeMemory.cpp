#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;
int n, k;

vector<int> numsCoin, tmp;
unordered_map<int, int> mm; // money -> min coins
int res = INT_MAX;

void moneyChange(vector<int> &d, int money, int curCoins)
{
    if (money == 0) {
        if (curCoins < res) {
            numsCoin = tmp;
            res = curCoins;
        }
        return;
    }
    if (money < 0) return;
    
    // Pruning: if current coins already >= best result, stop
    if (curCoins >= res) return;
    
    // Check if we already computed this money amount
    if (mm.find(money) != mm.end()) {
        return;
    }

    int minCoins = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (money >= d[i])  // Fixed: should be >= not >
        {
            tmp[i]++;
            
            // Recursive call
            moneyChange(d, money - d[i], curCoins + 1);
            
            // Update minCoins based on the result
            if (mm.find(money - d[i]) != mm.end()) {
                int tmpSum = mm[money - d[i]] + 1;
                if (tmpSum < minCoins) {
                    minCoins = tmpSum;
                }
            }
            
            tmp[i]--;
        }
    }
    
    // Only store if we found a valid solution
    if (minCoins != INT_MAX) {
        mm[money] = minCoins;
    }
}

int main() {
    freopen("input.inp", "r", stdin);
    cin >> n;

    vector<int> d(n);
    numsCoin.resize(n, 0);
    tmp.resize(n, 0);
    
    // Read coin denominations first
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    cin >> k;
    cout << "k: " << k << endl;
    
    // Initialize base cases: each coin denomination requires 1 coin
    for (int i = 0; i < n; i++) {
        mm[d[i]] = 1;
    }
    mm[0] = 0; // 0 money requires 0 coins
    
    moneyChange(d, k, 0);

    if (res == INT_MAX) {
        cout << "No solution" << endl;
        return 0;
    }
    else
    {
        cout << res << endl;
        for (int i = 0; i < n; ++i) {
            cout << d[i] << ": " << numsCoin[i] << endl;
        }
    }

    return 0;
}