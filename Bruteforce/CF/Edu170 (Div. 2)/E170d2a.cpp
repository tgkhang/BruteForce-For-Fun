/*
link:https://codeforces.com/contest/2025/problem/A
Educational Codeforces Round 170 (Rated for Div. 2) A
17/10/2024
rating:700
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        int n=s.length(),m=t.length();
        int l=0;
        for(;l<min(n,m) && s[l]==t[l]; ++l);
        
        int cost= n+m;
        int tmp= l+1+(n-l)+(m-l);
        cout<<min(cost,tmp)<<endl;
    }
}