// Given a set of positive integers and a number k, find the number of subsets with sum k.
// Number of subsets with sum 0 is 1 (the empty subset).
// For example,
// Input - 1, 2, 3, 4 and k = 4
// Output - 2

// 1. Recursive solution. For every element, include or exclude it in the subset. Exponential time.
// 2. DP solution. Time - O(N * k), Space - O(N * k).

#include <iostream>
#include <vector>
using namespace std;

int count_subsets1(const vector<int>& a, int sum);
int rec(const vector<int>& a, int sum, int index);
int count_subsets2(const vector<int>& a, int sum);

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	cout << count_subsets1(a, 6) << "\n";
	cout << count_subsets2(a, 6) << "\n";
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

int count_subsets2(const vector<int>& a, int sum)
{
	int n = a.size();
	// dp[i][j] = number of subsets upto index i that sum to j.
	int dp[n][sum + 1];
	
	// Number of subsets with sum 0 is 1
	for(int i = 0; i < n; i++)
		dp[i][0] = 1;
		
	// If only first element present in set
	for(int j = 1; j <= sum; j++) {
		if(a[0] == j)
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(a[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
		}
	}
	
	return dp[n - 1][sum];
}