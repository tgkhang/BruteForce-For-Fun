//900

#include <iostream>
using namespace std;
long long n,m;
long long find(long long x,long long y)
{
    if(x==1&&y==1)return 2;
    if(x==1&&y==m)return 2;
    if(x==n&&y==1)return 2;
    if(x==n&&y==m)return 2;
    
    //edge
    if(x==1||x==n||y==1||y==m)return 3;
    
    return 4;
    
}

int main()
{
    long long t;
    cin>>t;
    long long x1,y2,x2,y1;
    while(t--)
    {
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cout<<min(find(x1,y1),find(x2,y2))<<endl;
    }

    return 0;
}