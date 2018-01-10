// Given an array of positive integers, and a target value T, find the number of ways that you can
// add and subtract the values in the array to add up to T.
// For example,
// Input - 1, 1, 1, 1, 1 and T = 3
// Output - 5
// See below link for more details-
// https://leetcode.com/problems/target-sum/description/

// 1. Recursive solution. Exponential time.

#include <iostream>
#include <vector>
using namespace std;

int target_sum(const vector<int>& a, int target);
int rec(const vector<int>& a, int index, int sum, int target);

int main()
{
	vector<int> a = {1, 1, 1, 1, 1};
	cout << target_sum(a, 3) << "\n";
	return 0;
}

int target_sum(const vector<int>& a, int target)
{
	int n = a.size();
	return rec(a, n - 1, 0, target);
}

int rec(const vector<int>& a, int index, int sum, int target)
{
	if(index < 0) {
		if(sum == target)
			return 1;
		else
			return 0;
	}
	
	int plus_sum = rec(a, index - 1, sum + a[index], target);
	int minus_sum = rec(a, index - 1, sum - a[index], target);
	
	return plus_sum + minus_sum;
}