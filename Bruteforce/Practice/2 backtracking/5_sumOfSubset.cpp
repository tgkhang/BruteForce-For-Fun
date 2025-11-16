#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> result;
int t;

void sumOfSubset1(int i, int sum, int S, vector<int> &a, vector<int> &result)
{
    if (i == n)
    {
        if (sum == t)
        {
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i] == 1)
                    cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    else
    {
        if (sum + S >= t)
        {
            if (sum + a[i] <= t)
            {
                result[i] = 1;
                sumOfSubset1(i + 1, sum + a[i], S - a[i], a, result);
                result[i] = 0;
            }
            sumOfSubset1(i + 1, sum, S - a[i], a, result);
        }
    }
}

int main()
{
    vector<int> a = {3, 5, 6, 7};
    t = 15;
    n = a.size();

    int S = 0;
    for (auto i : a)
        S += i;

    result.resize(n, 0);

    sumOfSubset1(0, 0, S, a, result);
    return 0;
}