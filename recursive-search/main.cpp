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
void solve(int setup[4][4], int solution[4][4], bool& check, int& row, int& col, int& a, int& b)
{
	if (checkLayout(setup, solution))
	{
		check = true;
		return;
	}
	if (a > 3 || a < 0 || b > 3 || b < 0)
		return;
	setup[row][col] = setup[a][b];
	setup[a][b] = 0;
	row = a;
	col = b;
	printBoard(setup);
	cout << a << " " << b << endl;
	usleep(80000);
	if (!check)
		solve(setup, solution, check, row, col, row, --col);
	if (!check)
		solve(setup, solution, check, row, col, --row, col);
	if (!check)
		solve(setup, solution, check, row, col, ++row, col);
	if (!check)
		solve(setup, solution, check, row, col, row, ++col);
}
int main()
{
	int arr[4][4] =
	{
		{13, 2, 10, 3},
		{1, 12, 8, 4},
		{5, 0, 9, 6},
		{15, 14, 11, 7}
	};
	int solu[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 0}
	};
	int r = 2, c = 1, cc = 2;
	std::cout << ";\n";
	bool check = false;
	printBoard(arr);
	solve(arr, solu, check, r, c, r, cc);
	std::cout << "Done!\n";
	return 0;
}

