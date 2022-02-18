#include <fstream>
#include <string>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
void printBoard(int a[4][4], int r, int c)
{
	printf("\033[2J\033[1;1H");
	cout << "row " << r << ", col " << c << endl;
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
		check = true;
		return;
	}
	if (col == 0)
	{
		if (row < 3)
		{
			setup[row][col] = setup[row + 1][col];
			setup[row + 1][col] = 0;
			printBoard(setup, row + 1, 1);
	        	usleep(80000);
			solve(setup, solution, check, row + 1, col);
		}
		else
		{
			setup[row][col] = setup[row][col + 1];
                        setup[row][col + 1] = 0;
                        printBoard(setup, row, col + 1);
                        usleep(80000);
                        solve(setup, solution, check, row, col + 1);
		}

	}
	else if (row == 0)
	{
		if (col < 3)
		{
			setup[row][col] = setup[row][col + 1];
			setup[row][col + 1] = 0;
			printBoard(setup, row, col + 1);
        		usleep(80000);
			solve(setup, solution, check, row, col + 1);
		}
		else
		{
			setup[row][col] = setup[row + 1][col];
                        setup[row + 1][col] = 0;
                        printBoard(setup, row + 1, col);
                        usleep(80000);
                        solve(setup, solution, check, row + 1, col);
		}
	}
	else if (col == 3)
	{
		if (row < 3)
		{
			setup[row][col] = setup[row][col-1];
                	setup[row][col-1] = 0;
			printBoard(setup, row, col-1);
                	usleep(80000);
			solve(setup, solution, check, row, col-1);
		}
		else
		{
		 	setup[row][col] = setup[row-1][col];
                        setup[row-1][col] = 0;
                        printBoard(setup, row-1, col);
                        usleep(80000);
                        solve(setup, solution, check, row-1, col);
		}
	}
	else if (row == 3)
	{
		if (col < 3)
		{

			setup[row][col] = setup[row][col+1];
	                setup[row][col+1] = 0;
	        	printBoard(setup, row, col+1);
	        	usleep(80000);
		        solve(setup, solution, check, row, col+1);
		}
		else
		{
			setup[row][col] = setup[row-1][col];
                        setup[row-1][col] = 0;
                        printBoard(setup, row-1, col);
                        usleep(80000);
                        solve(setup, solution, check, row-1, col);
		}
	}
	else if (!check)
	{
		setup[row][col] = setup[row][col + 1];
                setup[row][col + 1] = 0;
		printBoard(setup, row, col + 1);
        	usleep(80000);
		solve(setup, solution, check, row, col + 1);
	}
}
int main()
{
	int arr[4][4] =
	{
		{4, 1, 3, 14},
		{5, 6, 7, 8},
		{9, 0, 11, 13},
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
	printBoard(arr, 2, 1);
	solve(arr, solu, check, 2, 1);
	std::cout << "Done!\n";
	return 0;
}

