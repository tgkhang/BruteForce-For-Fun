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
     int t;
     cin >> t;
     while (t--)   {
          ll x, y;
          cin >> x >> y;

          ll res = 0, add = 0;

          if (x > y)
          {
               // caculate area of the smaller square
               res = (x - 1) * (x - 1);
               if (x % 2 == 0)
               {
                    add = 2 * x - y;
               }
               else
               {
                    add = y;
               }
          }
          else
          {    
               // caculate area of the smaller square
               res = (y - 1) * (y - 1);
               if (y % 2 == 0)
               {
                    add = x;
               }
               else
               {
                    add = 2 * y - x;
               }
          }

          cout << res + add << endl;
     }

     return 0;
}
