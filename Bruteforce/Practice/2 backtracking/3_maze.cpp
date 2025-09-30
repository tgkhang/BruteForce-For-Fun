#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> result;

int rows[] = {0, 0, 1, -1};
int cols[] = {1, -1, 0, 0};

bool findPath(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        if (result[x][y] == 'G')
            return true;
        if (result[x][y] == '#')
            return false;
        if (result[x][y] == 'x')
            return false;

        result[x][y] = 'x';

        for (int i = 0; i < 4; i++)
        {
            int x1 = x + rows[i];
            int y1 = y + cols[i];
            if (findPath(x1, y1, n, m))
                return true;
        }

        result[x][y] = '.'; // backtrack
        return false;
    }

    return false;
}

int main()
{
    vector<string> maze = {
        "#S##.#",
        "#....#",
        ".#.#.#",
        "....##",
        "..##.G",
        "#....#"};

    result = maze;

    int n = maze.size();
    int m = maze[0].size();

    findPath(0, 1, n, m);

    for (const auto &row : result)
    {
        cout << row << endl;
    }

    return 0;
}
