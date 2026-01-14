#include<bits/stdc++.h>
using namespace std;



    int maxSumDivThree(vector<int>& a) {
        vector<int> one, two;
        int res = 0;
        for (auto i : a) {
            res += i;
            if (i % 3 == 1) {
                one.push_back(i);
            } else if (i % 3 == 2) {
                two.push_back(i);
            }
        }

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int r = res % 3;

        if (r == 0)
            return res;

        if (r == 1) {
            // remove smallest r=1,
            int opt1 = (!one.empty()) ? one[0] : INT_MAX;
            // remove 2 smallest r=2  => 4
            int opt2 = (two.size() >= 2) ? two[0] + two[1] : INT_MAX;
            res -= min(opt1, opt2);
        } else { // r=2
            // remove smalleset r2
            int opt1 = (!two.empty()) ? two[0] : INT_MAX ;
            // remove 2 smallest r1
            int opt2 = (one.size() >= 2) ? one[0] + one[1] : INT_MAX;
            res -= min(opt1, opt2);
        }

        return res;
    }
int main()
{
    return 0;
}