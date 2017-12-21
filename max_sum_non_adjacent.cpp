// Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
// For example,
// Input - [2, 4, 6, 8]
// Output - 12
// Input - [5, 1, 1, 5]
// Output - 10

// 1. Time - O(N), Space - O(1)
// 2. DP solution. Time - O(N), Space - O(N).
// 3. Space Optimized DP solution. Time - O(N), Space - O(1).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_sum1(const vector<int>& a)
{
	int incl = a[0];
	int excl = 0;
	for(int i = 1; i < a.size(); i++) {
		int excl_new = max(incl, excl);
		incl = a[i] + excl;
		excl = excl_new;
	}
	
	return max(incl, excl);
}

int max_sum2(const vector<int>& a)
{
	int n = a.size();
	vector<int> dp(n);
	dp[0] = a[0];
	dp[1] = max(a[1], a[0]);
	for(int i = 2; i < n; i++)
		dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
	
	return dp[n - 1];
}

int max_sum3(const vector<int>& a)
{
	int n = a.size();
	int first = a[0];
	int second = max(a[1], a[0]);
	int result = second;
	for(int i = 2; i < n; i++) {
		result = max(a[i] + first, second);
		first = second;
		second = result;
	}
	
	return result;
}

int main()
{
	vector<int> a = {5, 5, 10, -100, 10, 5}; // 25
	vector<int> b = {15, 9, 900, 10, 100, 1000}; // 1915
	int result = max_sum1(a);
	cout << result << "\n";
	result = max_sum1(b);
	cout << result << "\n";
	result = max_sum2(a);
	cout << result << "\n";
	result = max_sum2(b);
	cout << result << "\n";
	result = max_sum3(a);
	cout << result << "\n";
	result = max_sum3(b);
	cout << result << "\n";
	return 0;
}