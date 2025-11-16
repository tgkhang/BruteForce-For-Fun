#include<iostream>
#include<set>

using namespace std;
int main()
{
    int n;
    set<int>s;
    cin>>n;
    int x;
    for(int i=0;i<n;++i)
    {
        
        cin>>x;
        s.insert(x);
    }

    cout<<s.size();
    return 0;
}
