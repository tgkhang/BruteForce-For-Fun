#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> solutions; // To store all valid solutions
void printSolution(const vector<int> &board)
{
    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool promissing(int i, vector<int> &board)
{
    // 3 2 1 2
    for (int j = 0; j < i; ++j)
    {
        if (board[j] == board[i] || abs(board[j] - board[i]) == abs(i - j))
            return false;
    }
    return true;
}

// place a queen in row i
void solveVer1(int i, vector<int> board)
{
    if (promissing(i - 1, board))
    {
        if (i == n)
        {
            solutions.push_back(board);
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                board[i] = j;
                solveVer1(i + 1, board);
                // board[i] = -1;
            }
        }
    }
}

void solveVer2(int i, vector<int> &board)
{
    if (i == n)
    {
        solutions.push_back(board);
    }
    else
    {
        for (int j = 0; j < n; ++j)
        {
            board[i] = j;
            if (promissing(i, board))
                solveVer2(i + 1, board);
        }
    }
}

void solveVer3(int i, vector<int> &board)
{
    for (int j = 0; j < n; j++)
    {
        board[i] = j;
        if (promissing(i, board))
        {
            if (i == n - 1)
            {
                solutions.push_back(board);
            }
            else
            {
                solveVer3(i + 1, board);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 8; // Number of queens

    vector<int> board(n, -1);

    // solveVer1(0, board);
    // solveVer2(0, board);
    solveVer3(0, board);

    // print solution
    for (auto i : solutions)
    {
        printSolution(i);
    }
    cout << solutions.size() << endl;
    return 0;
}