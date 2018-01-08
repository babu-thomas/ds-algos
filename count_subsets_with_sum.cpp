// Given a set of positive integers and a number k, find the number of subsets with sum k.
// Number of subsets with sum 0 is 1 (the empty subset).
// For example,
// Input - 1, 2, 3, 4 and k = 4
// Output - 2

// 1. Recursive solution. For every element, include or exclude it in the subset. Exponential time.

#include <iostream>
#include <vector>
using namespace std;

int count_subsets1(const vector<int>& a, int sum);
int rec(const vector<int>& a, int sum, int index);

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	cout << count_subsets1(a, 6) << "\n";
	return 0;
}

int count_subsets1(const vector<int>& a, int sum)
{
	int n = a.size();
	return rec(a, sum, n - 1);
}

int rec(const vector<int>& a, int sum, int index)
{
	if(sum == 0)
		return 1;
	if(index < 0)
		return 0;
	if(a[index] > sum)
		return rec(a, sum, index - 1);
	
	return rec(a, sum, index - 1) + rec(a, sum - a[index], index - 1);
}