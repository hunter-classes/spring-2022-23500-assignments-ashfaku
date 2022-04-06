#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;
void print_vector(vector<int> a)
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}
int find_min_index(vector<int> a, int start_index, int stop_index){
	int min_index = start_index, i;
	for (i = start_index;i < stop_index;i++)
	{
		if (a[i] < a[min_index])
			min_index = i;
	}
	return min_index;
}

vector<int> ssort(vector<int> a)
{
	int i,min_index,j,tmp;
	int len = a.size();
	// loop through the vector from 0 to end
	for (i = 0; i < len;i++)
	{
		// find the smallest value from i to the end
		min_index = find_min_index(a,i,len);
		tmp = a[i];
		a[i] = a[min_index];
		a[min_index] = tmp;

	}
	return a;
}

/*
  left and right are already sorted
3  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
vector<int> merge(vector<int> left, std::vector<int> right)
{
	vector<int> merged;

	// your code here
	int l = 0;
	int r = 0;

	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r]){
			merged.push_back(left[l]);
			l++;
		}
		else
		{
			merged.push_back(right[r]);
			r++;
		}
	}

	// add any extra elements in left
	while (l < left.size())
	{
		merged.push_back(left[l]);
		l++;
	}
	// add any extra elements in right
	while (r < right.size())
	{
		merged.push_back(right[r]);
		r++;
	}
	return merged;
}
vector<int> msort(vector<int> v)
{
	vector<int> left, right;
	int i;
	if (v.size() < 2)
		return v;
	for (i = 0; i < v.size() / 2; i++)
		left.push_back(v[i]);
	for (; i < v.size(); i++)
		right.push_back(v[i]);
	return merge(msort(left), msort(right));
}
void qsort(vector<int>& a, int left, int right)
{
	if (right - left <= 0) // nothing to do
		return;
	int pivotIndex, mid = (right + left) / 2;
	if (a[left] >= a[right] && a[left] >= a[mid])
		pivotIndex = left;
	else if (a[mid] >= a[left] && a[mid] >= a[right])
		pivotIndex = mid;
	else
		pivotIndex = right;
	int pivot = a[pivotIndex], index = left - 1;
	for (int i = left; i <= right; i++)
	{
		if (a[i] < pivot)
		{
			index++;
			int hold = a[i];
			a[i] = a[index];
			a[index] = hold;
		}
	}
	if (mid == left || mid == right)
		return;
	qsort(a, left, index);
	qsort(a, index + 1, right);
}
int main()
{
	vector<int> left = {3,2,1, 4};
	vector<int> right = {};
	vector<int> mort = {10,9,8,7,6,5,4,3,2,1,0,-1,2,-3};
	//cout << mort.size();
	qsort(mort, 0, mort.size() - 1);
	qsort(left, 0, left.size() - 1);
	print_vector(mort);
	print_vector(left);
	return 0;
}
