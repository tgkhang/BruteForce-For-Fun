#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int findx(vector<int>&a, int l, int r, int x)
{

	while(l<=r)
	{
		//int m=(l+r)/2;
        int m = l + (r - l) / 2; 
		if(a[m]==x)return m;
		if(a[m]<x)l= m+1;
		else r=m-1;
	}
	return -1;
}
int main()
{
	int n,x;
	cin>>n>>x;
	vector<int>a(n);

	for(int i=0;i<n;++i)cin>>a[i];
	sort(a.begin(),a.end());

	for(int i=0;i<n-1;++i)
	{
		int t = findx(a,i+1,n-1,x-a[i]);
		if(t!=-1 )
		{
			cout<<i+1<<" "<<t+1;
			break;
		}
	}



	return 0;
}

