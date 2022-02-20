#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
void printBoard(vector<vector<int>> a)
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
bool checkLayout(vector<vector<int>> a, int b[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] != b[i][j])
				return false;
	}
	return true;
}
void solve(vector<vector<int>> setup, int solution[4][4], bool& check, int& row, int& col, int a, int b)
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
	cout << row << " " << col << endl;
	usleep(80000);
	if (!check)
		solve(setup, solution, check, row, col, row, col - 1);
	if (!check)
		solve(setup, solution, check, row, col, row - 1, col);
	if (!check)
		solve(setup, solution, check, row, col, row + 1, col);
	if (!check)
		solve(setup, solution, check, row, col, row, col + 1);
}
int main()
{
	vector<vector<int>> arr;
	vector<int> a, b, e, d;
	a.push_back(13);
	a.push_back(2);
	a.push_back(10);
	a.push_back(3);
	b.push_back(1);
	b.push_back(12);
	b.push_back(8);
	b.push_back(4);
	e.push_back(5);
	e.push_back(0);
	e.push_back(9);
	e.push_back(6);
	d.push_back(15);
	d.push_back(14);
	d.push_back(11);
	d.push_back(7);
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(e);
	arr.push_back(d);
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
	//swapping 2, 1 with 2,2 to begin with
	solve(arr, solu, check, r, c, r, cc);
	std::cout << "Done!\n";
	return 0;
}


