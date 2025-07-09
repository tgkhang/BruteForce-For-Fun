#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> bestSol;// best solution
vector <ll> curSol; //current solution
vector <ll> a; // input value
ll n, k, curSum = 0; 

void bruteForce (ll i, ll left, ll coinNum){
    if (i == k){ // check when the solution space is completed
        if( left == 0 && (curSum > coinNum || bestSol.empty()))
        {
            bestSol = curSol;
            curSum = coinNum;
        }
        return;
    }
    
    int t = left / a[i];// maximum of ith coin 
    
    
    for(int j = 0; j <= t; ++j){
        curSol[i] = j;
        bruteForce( i + 1, left - j * a[i] ,coinNum + j);
    }
}

int main(){
    cin>>k;
    
    for(auto i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        curSol.push_back(0);
    }
    
    cin>>n;
    bruteForce(0, n, 0);
    
    
    if (bestSol.empty()){
        cout << "No solution";
    }
    else {
        for(ll i = 0; i < k; ++i){
            cout << a[i] <<": "<< bestSol[i] << endl;
        }
    }
    return 0;
}