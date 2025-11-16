#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{

	string s;
	cin >> s;
	sort(s.begin(),s.end());

	vector<string>res;


	do{
		res.push_back(s);
	}
	while(next_permutation(s.begin(),s.end()));


	cout<<res.size()<<endl;
	for(auto i:res)cout<<i<<endl;

	return 0;
}