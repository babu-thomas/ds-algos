// Find the length of the longest subsequence of a given sequence of integers such that all elements
// of the subsequence are sorted in increasing order.
// For example,
// Input - 10, 22, 9, 33, 21, 50, 41, 60, 80
// Output - 6

// 1. Solution using DP. Time - O(N^2), Space - O(N).

#include <iostream>
#include <vector>
using namespace std;

int lis1(vector<int> a)
{
	int n = a.size();
	if(n == 0)
		return 0;
	
	vector<int> dp(n, 1);
	int max = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			int old_len = dp[i];
			int new_len = dp[j] + 1;
			if(a[j] < a[i] && new_len > old_len)
				dp[i] = new_len;
		}
		if(dp[i] > max)
			max = dp[i];
	}
	return max;
}

int main()
{
	vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	vector<int> b = {3, 10, 2, 1, 20};
	cout << lis1(a) << "\n";
	cout << lis1(b) << "\n";
	return 0;
}