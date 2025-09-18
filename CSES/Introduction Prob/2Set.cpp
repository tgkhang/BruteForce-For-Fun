/// divide 1..n to 2 equal set

/*
4 consecitive: k k+1 k+2 k+3
can devide into
k + (k+3) = (k+1) + (k+2) = 2k +3
(k start from 0)

and 3 consecutive: k k+1 k+2
k = k+1 k+2= 2k +3

*/
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <deque>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    if (n * (n + 1) / 2 % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    vector<int> v1, v2;

    // The 4-element pattern only works on groups that are multiples of 4.
    int j = 0;
    if (n % 4 != 0)
        j = 3;
    else
        j = 4;

    for (int i = 0; i < (n - 1) / 4; ++i)
    {
        v1.push_back(4 * i + 1 + j);
        v1.push_back(4 * i + 4 + j);
        v2.push_back(4 * i + 2 + j);
        v2.push_back(4 * i + 3 + j);
    }
    // base case
    // The 4-element pattern only works on groups that are multiples of 4.
    if (n % 4 != 0)
    {
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    else
    {
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(3);
        v2.push_back(2);
    }

    cout << "YES\n";
    cout << v1.size() << "\n";
    for (auto i : v1)
        cout << i << " ";
    cout << "\n";
    cout << v2.size() << "\n";
    for (auto i : v2)
        cout << i << " ";
    cout << "\n";

    return 0;
}

/*
1 no %2 = 1

1 2  no %2 =1
1 2 3 4 5=15 %2 =1


n=3
1 2 3 = 6yes
1 2
3

1 2 3 4 = 10
yes
4 1
2 3

1 2 3 4 5 6 7 = 28
1 2 4 7
3 5 6
phai chia het cho 2

0->   less than(n-1)/4
(4 * i + 1 + j)
(4 * i + 4 + j)
(4 * i + 2 + j)
(4 * i + 3 + j)
*/