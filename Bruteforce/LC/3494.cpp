#include <bits/stdc++.h>

using namespace std;
long long minTime(vector<int> &skill, vector<int> &mana)
{
    int n = skill.size(), m = mana.size();
    vector<long long> done(n + 1, 0);
    // done[i] : finish time of previous potion

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
            done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];

        for (auto i : done)
            cout << i << " ";
        cout << endl;

        // make sure it is passed immediately
        for (int i = n - 1; i > 0; --i)
            done[i] = done[i + 1] - 1LL * mana[j] * skill[i];

        for (auto i : done)
            cout << i << " ";
        cout << endl;
        cout << endl;
    }

    return done[n];
}
int main()
{
    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana = {5, 1, 4, 2};

    cout << minTime(skill, mana);

    return 0;
}