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




/*
    p1,p2,p3 is point of 3 people
    p1<p2<p3 (gt)
    2 case:
    p1+p2 < p3 
        -> p1 play p1 draws game with p3
        -> p2 play p2 draws game with p3 
        -> the res can not increase any more
    p1 + p2 > p3 
        -> p1> p3-p2
        -> p1 plays p3-p2 games draw with p3 ; p1 reduce by p3-p2, p3 and p2 become equal
        -> the rest of p1 is p1-(p3-p2) is a even due to p1+p2+p3 even
        -> p1 point draws game is smaller tham p3 and p2, devide the draws game for p3 and p2 = (p1-p3+p2)/2
        -> the rest of p3 and p2 is equal = p2 - (p1-(p3-p2))/2 
        -> sum all the draw we have p1 + p2 +p3 /2
    
*/
void run_case()
{

    ll p1,p2,p3;
    cin>>p1>>p2>>p3;

    if((p1+p2+p3 )%2!=0){cout<<-1;return;}
    cout<< min((p1+p2+p3)/2, p1+p2);

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


