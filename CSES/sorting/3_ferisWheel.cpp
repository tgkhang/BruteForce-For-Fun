#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    
    sort(weights.begin(), weights.end());

    int gondolas = 0;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        // Try to pair the lightest person with the heaviest person
        if (weights[left] + weights[right] <= x)
        {
            left++; // Both people can go in the same gondola
        }
        right--; // The heaviest person goes in a gondola
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}