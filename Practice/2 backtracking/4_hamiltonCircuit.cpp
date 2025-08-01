#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<vector<int>> a;
vector<int> res;

// Renamed to 'promising' and fixed logic
bool promising(int i, int j)
{
    // Check if the last node connects to the start to form a cycle
    if (i == n - 1 && a[j][res[0]] == 0)
        return false;
    // Check if the previous node connects to the current node
    else if (a[res[i - 1]][j] == 0)
        return false;
    else
    {
        // Check if node j is already in the path
        for (int idx = 0; idx < i; ++idx)
        {
            if (res[idx] == j)
                return false;
        }
    }
    return true;
}

bool backTracking(int i)
{
    if (i == n)
    {
        // Found a Hamiltonian cycle
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (promising(i, j))
        {
            res.push_back(j);
            if (backTracking(i + 1))
                return true;
            res.pop_back();
        }
    }
    return false;
}

int main()
{
    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    cin >> k;

    res.push_back(k);

    if (backTracking(1))
    {
        for (auto i : res)
            cout << i << " ";
        cout << res[0]; // To show the cycle
    }
    else
        cout << "No solution";

    return 0;
}