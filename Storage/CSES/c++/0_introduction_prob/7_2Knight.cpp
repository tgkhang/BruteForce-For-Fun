#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    ll n;



    cin>>n;
    for(int k=1;k<=n;++k)
    {
        //total squares on the board
        ll a1= k*k;
        //total ways to choose 2 squares
        ll a2= a1*(a1-1)/2; // nC2
        //ways to choose 2 squares such that knight cannot go from one to another
        if(k>2)
        {
            /*
                2 ways attach in 2x3
                2 wasy attack in 3x2

                find way to put the 2x3 and 3x2 into initial square
                (k-1)*(k-2)  *  2 (number of ways)
                (k-2)* (k-1) *2
                plus them
            */
            a2-= 4* (k-1)*(k-2);

        }

        cout<<a2<<"\n";
    }



    return 0;
}
