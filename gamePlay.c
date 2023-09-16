#include <stdio.h>

int can_put(int, int, int board[][8], int);			   // returns 1 if can be put cant 0 if cannot
int prior_put(int, int board[][8], int result[], int); // returns 1 if can be put cant 0 if cannot
int main(int argc, char const *argv[])
{
	int color, result[2];
	int board[8][8] = {{1, 8, 3, 2, 2, 3, 8, 1}, {8, 9, 7, 6, 6, 7, 9, 8}, {3, 7, 4, 5, 5, 4, 7, 3}, {2, 6, 5, 0, 0, 5, 6, 2}, {2, 6, 5, 0, 0, 5, 6, 2}, {3, 7, 4, 5, 5, 4, 7, 3}, {8, 9, 7, 6, 6, 7, 9, 8}, {1, 8, 3, 2, 2, 3, 8, 1}};
	if (*argv[9] == '1')
		color = 11;
	else
		color = 12;
	for (int i = 1; i < 9; i++)
		for (int j = 0; j < 8; j++)
		{
			if (argv[i][j] == '1')
				board[i - 1][j] = 11;
			else if (argv[i][j] == '2')
				board[i - 1][j] = 12;
		}
	for (int i = 1; i < 10; i++)
		if (prior_put(i, board, result, color))
		{
			printf("%d %d", result[1], result[0]);
			return 0;
		}
}
int can_put(int i, int j, int board[][8], int color)
{
	// top left
	if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != color && board[i - 1][j - 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i - x < 0 || j - x < 0 || board[i - x][j - x] < 10)
				break;
			if (board[i - x][j - x] == color)
				return 1;
		}
	// upper side
	if (i - 1 >= 0 && board[i - 1][j] != color && board[i - 1][j] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i - x < 0 || board[i - x][j] < 10)
				break;
			if (board[i - x][j] == color)
				return 1;
		}
	// top right
	if (i - 1 >= 0 && j + 1 <= 7 && board[i - 1][j + 1] != color && board[i - 1][j + 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i - x < 0 || j + x > 7 || board[i - x][j + x] < 10)
				break;
			if (board[i - x][j + x] == color)
				return 1;
		}
	// right side
	if (j + 1 <= 7 && board[i][j + 1] != color && board[i][j + 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (j + x > 7 || board[i][j + x] < 10)
				break;
			if (board[i][j + x] == color)
				return 1;
		}
	// down right
	if (i + 1 <= 7 && j + 1 <= 7 && board[i + 1][j + 1] != color && board[i + 1][j + 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i + x > 7 || j + x > 7 || board[i + x][j + x] < 10)
				break;
			if (board[i + x][j + x] == color)
				return 1;
		}
	// down side
	if (i + 1 <= 7 && board[i + 1][j] != color && board[i + 1][j] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i + x > 7 || board[i + x][j] < 10)
				break;
			if (board[i + x][j] == color)
				return 1;
		}
	// down left
	if (j - 1 >= 0 && i + 1 <= 7 && board[i + 1][j - 1] != color && board[i + 1][j - 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (i + x > 7 || j - x < 0 || board[i + x][j - x] < 10)
				break;
			if (board[i + x][j - x] == color)
				return 1;
		}
	// left side
	if (j - 1 >= 0 && board[i][j - 1] != color && board[i][j - 1] > 10)
		for (int x = 2; x < 8; x++)
		{
			if (j - x < 0 || board[i][j - x] < 10)
				break;
			if (board[i][j - x] == color)
				return 1;
		}
	return 0;
}
int prior_put(int priority, int board[][8], int result[], int color)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == priority && can_put(i, j, board, color))
			{
				result[0] = i;
				result[1] = j;
				return 1;
			}
	return 0;
}