#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int i=0,t=0,res=0;
      while(abs(t)<=n)
      {
          i++;
          int tmp=2*i-1;
          if(res==0)t-=tmp;
          else t+=tmp;
          res=1-res;
      }
      if(res!=0)cout<<"Sakurako";
      else cout<<"Kosuke";
      cout<<endl;
    }
}

//easy math brute force
//26/10/2024
// rating 700