#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> board;
int rows[] = {2, 1, -1, -2, -2, -1, 1, 2};
int cols[] = {1, 2, 2, 1, -1, -2, -2, -1};

void printSolution(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void KnightTour(int move, int x, int y, vector<vector<int>> &board)
{
    for (int i = 0; i < 8; i++)
    {
        int x1 = x + rows[i];
        int y1 = y + cols[i];

        // wrong
        // if (
        //     board[x1][y1] == -1 && // Check if the cell is unvisited
        //     x1 >= 0 && x1 < n &&   // Check if within bounds
        //     y1 >= 0 && y1 < n      // Check if within bounds
        // )
        if (
            x1 >= 0 && x1 < n &&
            y1 >= 0 && y1 < n &&
            board[x1][y1] == -1)
        {
            board[x1][y1] = move;
            if (move == n * n)
                printSolution(board);
            else
            {
                KnightTour(move + 1, x1, y1, board);
            }

            // remember to backtrack
            board[x1][y1] = -1;
        }
    }
}

int main()
{
    n = 5;
    // WOW 🤣
    board.resize(n, vector<int>(n, -1));

    board[2][2] = 1;
    KnightTour(2, 2, 2, board);

    return 0;
}