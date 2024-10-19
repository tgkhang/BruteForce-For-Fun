/*
tag: 900
link:https://codeforces.com/problemset/problem/755/A
topic graph

*/

#include <bits/stdc++.h>
using namespace std;




bool prime(int n)
{
    if (n < 2) return false;
    for (int x = 2; x*x <= n; x++)
    {
    if (n%x == 0) return false;
    }
    return true;
}

int main()
{
    int n,res=1;
  
    cin>>n;
    while(prime(n*res+1)==true)
    {
        res++;
    }
    cout<<res;
    

    return 0;
}
