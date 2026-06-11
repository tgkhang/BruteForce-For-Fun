#include <bits/stdc++.h>

// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// s.find_by_order(2) order_of_key(9)
using namespace std;

// special data tructure
// #define NDEBUG
// #include <ext/pb_ds/assoc_container.hpp>// Common file
// using namespace __gnu_pbds;

// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define NDEBUG

#define fi first
#define se second
#define vt vector
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define FOR1(i, a, b) for (ll i = a; i < b; ++i)
#define FOR2(i, a, b) for (ll i = a; i > b; --i)
#define FOR3(i, a, b) for (ll i = a; i <= b; ++i)
#define FOR4(i, a, b) for (ll i = a; i >= b; --i)
// note not declare var i and cal for1,2 at same time
#define EACH(x, a) for (auto &x : a)
#define jj "\n"
#define debug printf("I am here\n")
#define space printf(" ")

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

typedef long long ll;
typedef long double ld;
const ll base = 1e9 + 7;
const float pi = 3.1415926535897932384626433;
typedef pair<ll, ll> PLL;
typedef unsigned long long ULL;

// operator =?
//  ko bit operator nên xài do kieeur data cung ko toi uu lam
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
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size() // ??

ll n, m;
int d4i[] = {-1, 0, 1, 0};
int d4j[] = {0, 1, 0, -1};
int d8i[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d8j[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool dfs(vector<vector<char>> &a, int i, int j, int ei, int ej)
{
    if (i == ei && j == ej)
    {
        cout << "YES" << jj;
        return true;
    }

    for (int k = 0; k < 4; ++k)
    {
        int i1 = i + d4i[k];
        int j1 = j + d4j[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && (a[i1][j1] == '.' || a[i1][j1] == 'B'))
        {
            a[i][j] = 'a';
            if (dfs(a, i1, j1, ei, ej))
                return true;
            a[i][j] = '.';
        }
    }
    return false;
}

void printSolution(vector<vector<char>> &a, int si, int sj, int ei, int ej)
{
    string res = "";
    int i = si, j = sj;
    while (i != ei || j != ej)
    {
        if (i > 0 && a[i - 1][j] == 'a')
        {
            res += 'U';
            a[i][j] = '#';
            i--;
        }
        else if (i < n - 1 && a[i + 1][j] == 'a')
        {
            res += 'D';
            a[i][j] = '#';
            i++;
        }
        else if (j > 0 && a[i][j - 1] == 'a')
        {
            res += 'L';
            a[i][j] = '#';
            j--;
        }
        else if (j < m - 1 && a[i][j + 1] == 'a')
        {
            res += 'R';
            a[i][j] = '#';
            j++;
        }
    }
    cout << res.size() << jj;
    cout << res << jj;
}

void run_case()
{
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));

    int si, sj, ei, ej;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'B')
            {
                ei = i;
                ej = j;
            }
        }

    if (dfs(a, si, sj, ei, ej))
    {
        printSolution(a, si, sj, ei, ej);
    }
}
void run_with_t()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
        cout << jj;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
// freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    run_with_t();
    // run_case();
    return 0;
}