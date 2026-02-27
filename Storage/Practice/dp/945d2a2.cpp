#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<stdio.h>
#include<set>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cmath>
#include<list>
#include<stdlib.h>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<climits>
//????
#include<array>
#include<bitset>
#include<cassert>
#include<chrono>
#include<cstring>
#include<functional>
#include<numeric>
#include<random>


//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//s.find_by_order(2) order_of_key(9)

using namespace std;

//#include<bits/stdc++.h>
//special data tructure
//#define NDEBUG
#include <ext/pb_ds/assoc_container.hpp>// Common file
using namespace __gnu_pbds;


#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i,a,b) for(ll i=a;i<=b;++i)
#define FOR2(i,a,b) for(ll i=a;i>=b;--i)
#define EACH(x, a) for (auto& x: a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base=1e9+7;
const float pi=3.1415926535897932384626433;
typedef pair<ll,ll> PLL;
typedef unsigned long long  ULL;

// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};  // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};  // Hexagonal Direction

//start from 0

//operator =?
// ko bit operator nên xài do kieeur data cung ko toi uu lam
/*
bool equal(auto x,auto y)
{
    if (abs(x-y) < 1e-9) return true;
    else return false;
}*/

/*
template<typename T>
void output_vector(const T &v,  int start = -1, int end = -1)
{
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] << (i < end - 1 ? ' ' : '\n');
}
*/

#define all(a) a.begin(), a.end()
#define rall(v) v.rbegin(),v.rend()




void run_case1()
{
   ll n;
   cin>>n;
   ll tmp=n;
   vector<ll>res;

   ll index=0;

   while(tmp!=0)
   {
       if( ((tmp>>index)&1)==1 )
       {
            res.push_back(tmp);
            cout<<tmp<<" ";
            tmp= ( tmp & (~(1<<index)) ) ;

       }
       index++;
   }


   res.push_back(n);

   //cout<<res.size()<<jj;
//   for(auto i:res)
//   cout<<res[i]<<" ";
}


bool checking(int p1,int p2,int p3,int a,int b,int c)
{
    int t1=p1-a-b;
    int t2=p2-a-c;
    int t3=p3-b-c;
    if(t1<0||t2<0||t3<0) return false;
    if(t1%2==0 && t2%2==0 && t3%2==0)return true;
    return false;
}

void run_case()
{
    ll p1,p2,p3;
    cin>>p1>>p2>>p3;

    if((p1+p2+p3 )%2!=0){cout<<-1;return;}

    int n=p1+p2+p3;
    int kq=-1;
    for(int i=0;i<=n;i+=2)
    {

        //cout<<i<<jj;
        FOR1(a,0,n)
        FOR1(b,0, n)
        FOR1(c,0,n-a)
        {
            //cout<<a<<" "<<b<<" "<<c<<" "<<checking(p1,p2,p3,a,b,c)<<jj;
            if(checking(p1,p2,p3,a,b,c)&&(a+b+c==i/2))
            {
                 kq=i;
            //cout<<a<<" "<<b<<" "<<c<<" "<<kq<<jj;
            }
        }


    }
    cout<<kq/2;
}


void run_with_t()
{
    int t;
    cin>>t;
    while(t--)
    {
        run_case();
        cout<<jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE



    run_with_t();
    //run_case();
    return 0;
}

