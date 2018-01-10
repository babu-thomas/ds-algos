// Given an array of positive integers, and a target value T, find the number of ways that you can
// add and subtract the values in the array to add up to T.
// For example,
// Input - 1, 1, 1, 1, 1 and T = 3
// Output - 5
// See below link for more details-
// https://leetcode.com/problems/target-sum/description/

// 1. Recursive solution. Exponential time.
// 2. DP solution. Time - O(N * R), Space - O(N * R) where R is the range of sum values.
//	  For example, for the above example input max sum is 5 and min sum is -5.
//	  So, R = -5 to 5, ie 5 * 2 + 1 = 11.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int target_sum1(const vector<int>& a, int target);
int rec(const vector<int>& a, int index, int sum, int target);
int target_sum2(const vector<int>& a, int target);

int main()
{
	vector<int> a = {0, 0, 0, 0, 0, 0, 1};
	cout << target_sum1(a, 1) << "\n";
	cout << target_sum2(a, 1) << "\n";
	return 0;
}

int target_sum1(const vector<int>& a, int target)
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

int target_sum2(const vector<int>& a, int target)
{
	int sum = accumulate(a.begin(), a.end(), 0);
	if(target < -sum || target > sum)
		return 0;
	
	int n = a.size();
	// dp[i][j] = number of ways for elements upto index i to reach sum j.
	int dp[n + 1][2 * sum + 1];
	
	// If only first element is present
	for(int j = -sum; j <= sum; j++) {
		if(a[0] == j || a[0] == -j)
			dp[0][j + sum] = 1;
		else
			dp[0][j + sum] = 0;
	}
	
	// Special case if first element is zero because then there are 2 ways to get sum 0
	if(a[0] == 0)
		dp[0][sum] = 2;
	
	for(int i = 1; i < n; i++) {
		for(int j = -sum; j <= sum; j++) {
			dp[i][j + sum] = 0;
			if(j - a[i] >= -sum)
				dp[i][j + sum] += dp[i - 1][j - a[i] + sum];
			if(j + a[i] <= sum)
				dp[i][j + sum] += dp[i - 1][j + a[i] + sum];
		}
	}
	
	return dp[n - 1][target + sum];
}