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
bool checkMove(vector<vector<vector<int>>>& l, vector<vector<int>> setup)
{
	if (l.size() > 2)
		l.erase(l.begin());
	for (int i = 0; i < l.size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (setup[j][k] == l[i][j][k])
					counter++;
			}
		}
		if (counter == 16) // if the board entirely matches with one in the vector
				return true;
	}
	return false;
}
void solve(vector<vector<int>> setup, int solution[4][4], bool& check, int& row, int& col, int a, int b, vector<vector<vector<int>>>& c)
{
	if (checkLayout(setup, solution))
	{
		check = true;
		printBoard(setup);
		return;
	}
	if (a > 3 || a < 0 || b > 3 || b < 0)
		return;
	int rowCount = 0, colCount = 0;
	for (int i = 0; i < 4; i++)
	{
		if (setup[a][i] == solution[a][i])
			rowCount++;
		if (setup[i][b] == solution[i][b])
			colCount++;
	}
	if (rowCount == 4 || colCount == 4) // to check if the row im wanting to swap with is already done?
		return;
	setup[row][col] = setup[a][b];
	setup[a][b] = 0;
	int rh = row, ch = col; // to hold the value of row/col if i wanna undo the swap
	row = a;
	col = b;
	printBoard(setup);
	cout << row << " " << col << endl;
	if (checkMove(c, setup) && !check)
        {
		setup[row][col] = setup[rh][ch];
        	setup[rh][ch] = 0;
        	row = rh;
        	col = ch; // to undo the swap and try another direction?
		printBoard(setup);
		usleep(80000);
                solve(setup, solution, check, row, col, row, col + 1, c);
		return;
        }
	usleep(80000);
	if (!check)
		c.push_back(setup);
	if (!check)
		solve(setup, solution, check, row, col, row, col - 1, c);
	if (!check)
		solve(setup, solution, check, row, col, row - 1, col, c);
	if (!check)
		solve(setup, solution, check, row, col, row + 1, col, c);
	if (!check)
		solve(setup, solution, check, row, col, row, col + 1, c);
}
int main()
{
	vector<vector<vector<int>>> list;
	vector<vector<int>> arr;
	vector<int> a, b, e, d;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(4);
	e.push_back(9);
	e.push_back(10);
	e.push_back(11);
	e.push_back(8);
	d.push_back(13);
	d.push_back(14);
	d.push_back(15);
	d.push_back(12);
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
	int r = 0, c = 0;
	std::cout << ";\n";
	bool check = false;
	printBoard(arr);
	//swapping 2, 1 with 2,2 to begin with
	solve(arr, solu, check, r, c, r+1, c, list);
	std::cout << "Done!\n";
	return 0;
}
