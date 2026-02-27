// apply boyer-moore voting algorithm to find majority element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &a)
{
    int n = a.size();

    int t = -1, count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (count == 0)
        {
            t = a[i];
            count = 1;
        }
        else
        {
            if (a[i] == t)
                count++;
            else
                count--;
        }
    }

    int check = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == t)
            check++;
    }
    if (check > n / 2)
        return t;
    return -1;
}

int main()
{
    vector<int> a = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(a);
    return 0;
}