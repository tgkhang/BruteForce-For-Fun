#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> maze;

int rows[] = {0, 0, 1, -1};
int cols[] = {1, -1, 0, 0};

bool findPath(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int x1 = x + rows[i];
        int y1 = y + cols[i];

        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m)
        {
            if (maze[x1][y1] == 'G')
            {
                maze[x1][y1] = 'x';
                return true;
            }

            if (maze[x1][y1] == '#')
                continue;
            if (maze[x1][y1] == 'x')
                continue;

            maze[x1][y1] = 'x'; // mark as visited

            if (findPath(x1, y1))
                return true;

            maze[x1][y1] = ' '; // backtrack
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    cin.ignore();

    maze.resize(n);

    for (int i = 0; i < n; ++i)
    {
        getline(cin, maze[i]);
        // cout<<maze[i].size();
    }

    int t1, t2;
    bool found = false;

    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == 'S')
            {
                t1 = i;
                t2 = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    maze[t1][t2] = 'x';

    if (findPath(t1, t2))

        for (auto i : maze)
            cout << i << endl;
    else
        cout << "No solution";

    return 0;
}