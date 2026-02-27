#include <bits/stdc++.h>
using namespace std;


void HNTower(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }
    HNTower(n - 1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    HNTower(n - 1, aux, to, from);
}

int main ()
{
    int n;
    cin>>n;
    
    return 0;
}