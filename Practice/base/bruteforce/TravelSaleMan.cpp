#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> result;
ll minDis = 1e18;
vector<vector<ll>> dis;

ll caculateDistance(vector<ll> &r)
{
    ll t = 0; // total distance

    for (int i = 1; i < r.size(); ++i)
    {
        if (dis[r[i - 1]][r[i]] == -1)
            return 1e18;

        t += dis[r[i - 1]][r[i]];
    }

    // go back to start point
    if (dis[r[r.size() - 1]][r[0]] == -1)
        return 1e18;
    t += dis[r[r.size() - 1]][r[0]];

    return t;
}
 
void bruteForce(ll i, vector<ll> &currentRoute)
{
    if (i == n)
    {
        ll currentDistance = caculateDistance(currentRoute);
        if (currentDistance < minDis)
        {
            result = currentRoute;
            minDis = currentDistance;
        }
        return;
    }

    for (int j = i; j < n; j++)
    {
        swap(currentRoute[i], currentRoute[j]);
        bruteForce(i + 1, currentRoute);
        swap(currentRoute[i], currentRoute[j]);
    }
}
int main()
{
    cin >> n;
    dis.resize(n);

    vector<ll> currentRoute;
    for (int i = 0; i < n; ++i)
        currentRoute.push_back(i);

    for (int i = 0; i < n; i++)
    {
        dis[i].resize(n); // distance array
        for (int j = 0; j < n; j++)
            dis[i][j] = -1;
    }

    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        a--;
        b--;
        dis[a][b] = c;
        dis[b][a] = c;
    }

    bruteForce(1, currentRoute);

    if (result.empty())
        cout << "No solution";
    else
    {

        for (int i = 0; i < n; ++i)
            cout << result[i] + 1 << " ";
        cout << result[0] + 1 << endl;
        cout << minDis << endl;
    }

    return 0;
}