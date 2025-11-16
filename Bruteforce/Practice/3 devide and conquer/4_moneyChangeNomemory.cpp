/*
this is a C++ program to solve the money change problem using a brute-force approach without memoization
INput format:
4
25 10 5 1
72
Output format:
6
25: 2
10: 2
5: 0
1: 2
*/

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;
int n, k;

vector<int> numsCoin, tmp;
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

    for (int i = 0; i < n; ++i)
    {
        if (money >= d[i])
        {
            tmp[i]++;
            moneyChange(d, money - d[i], curCoins + 1);
            tmp[i]--;
        }
    }
}

int main() {
    freopen("input.inp", "r", stdin);
    cin >> n;

    vector<int> d(n);
    numsCoin.resize(n, 0);
    tmp.resize(n, 0);
    
  
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    cin >> k;
    cout << "k: " << k << endl;
    

    
    moneyChange(d, k, 0);

    if (res == INT_MAX) {
        cout << "No solution" << endl;
        
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