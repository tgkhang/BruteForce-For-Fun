#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

char board[9][9];
int col[9];
int res = 0;

bool promising(int row, int c)
{
	for (int j = 1; j < row; j++)
	{
		/*
		col[j] - c = horizontal distance between the two queens

		j - row = vertical distance between the two queens

		Two queens are on the same diagonal if these distances are equal! This forms a perfect 45° diagonal.
		*/
		if (col[j] == c || abs(col[j] - c) == abs(j - row))
		{
			return false;
		}
	}
	return true;
}

void placeQueen(int i)
{
	if (i == 9)
	{
		res++;
		return;
	}

	for (int j = 1; j <= 8; ++j)
	{
		if (board[i][j] != '*' && promising(i, j))
		{
			col[i] = j;
			placeQueen(i + 1);
		}
	}
}

int main()
{
	for (int i = 1; i <= 8; ++i)
		for (int j = 1; j <= 8; ++j)
		{
			cin >> board[i][j];
		}

	placeQueen(1);
	cout << res;
	return 0;
}