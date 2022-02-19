#include <fstream>
#include <string>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
void printBoard(int a[4][4])
{
	printf("\033[2J\033[1;1H");
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
}
bool checkLayout(int a[4][4], int b[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] != b[i][j])
				return false;
	}
	return true;
}
void solve(int setup[4][4], int solution[4][4], bool& check, int row, int col)
{
	if (checkLayout(setup, solution))
	{
		cout << "HUH" << endl;
		check = true;
		return;
	}
	if (row < 3)
	{
		int i = setup[row+1][col] - 1, r = i/4, c = i%4;
		if (r <= row || c != col)
		{
			setup[row][col] = setup[row+1][col];
			setup[row+1][col] = 0;
			printBoard(setup);
                        usleep(80000);
			solve(setup, solution, check, row+1, col);
		}
	}
	if (col < 3)
	{
		int i = setup[row][col + 1] - 1, r = i/4, c = i%4;
		if (col >= c || row != r)
		{
			setup[row][col] = setup[row][col+1];
			setup[row][col + 1] = 0;
			printBoard(setup);
                        usleep(80000);
			solve(setup, solution, check, row, col+1);
		}
	}
	if (row > 0)
        {
              int i = setup[row-1][col] - 1, r = i/4, c = i%4;
              if (r > row)
              {
                        setup[row][col] = setup[row-1][col];
                        setup[row-1][col] = 0;
                        printBoard(setup);
                        usleep(80000);
                        solve(setup, solution, check, row-1, col);
              }
        }
	if (col > 0)
	{
		int i = setup[row][col-1] - 1, r = i/4, c = i%4;
		if (col < c)
		{
			setup[row][col] = setup[row][col-1];
			setup[row][col-1] = 0;
			printBoard(setup);
			usleep(80000);
			solve(setup, solution, check, row, col-1);
		}
	}
}
int main()
{
	int arr[4][4] =
	{
		{0, 1, 3, 14},
		{5, 8, 6, 7},
		{9, 4, 11, 13},
		{2, 10, 15, 12}
	};
	int solu[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 0}
	};
	std::cout << ";\n";
	bool check = false;
	printBoard(arr);
	cout << 0 << " " << 0 << endl;
	solve(arr, solu, check, 0, 0);
	std::cout << "Done!\n";
	return 0;
}

