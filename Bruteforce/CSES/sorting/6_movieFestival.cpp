/*choose the eariliest ending*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    int res=0, lastTimeEnd=0;

    for(int i=0;i<n;++i)
    {
        if(a[i].first>= lastTimeEnd)
        {
            res++;
            lastTimeEnd=a[i].second;
        }
    }

    cout<<res;
    return 0;
}