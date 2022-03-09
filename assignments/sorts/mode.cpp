#include <iostream>
#include <vector>
#include <climits>
using std::vector;

int count(std::vector<int> v, int value)
{
	int c = 0;
	for (int i: v)
		c += (i == value ? 1 : 0);
	return c;
}
int largest(std::vector<int> v)
{
	int large = INT_MIN;
	for (int i: v)
		large = (i > large ? i : large);
	return large;
}
int mode(std::vector<int> v)
{
	int mode = INT_MIN, num;
	if (v.size() == 0)
		return std::length_error("There cannot be a mode with a list of 0 elements");
	vector<int> l; // so i dont count each number more than once maybe
	for (int i : v)
	{
		int c;
		if (!l.contains(i) && (c = count(v, i)) > mode)
		{
			mode = c;
			num = i;
		}
		if (!l.contains(i))
			l.push_back(i);
	}
	return num;
}
int main()
{
	return 0;
}
