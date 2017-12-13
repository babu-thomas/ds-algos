// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it
// can be decoded.

// For example,
// Input -  111
// Output - 3, since it could be decoded as 'aaa, 'ka', and 'ak'.

// 1. Solution using recursion. Exponential time complexity.
// 2. Top down DP solution
// 3. Bottom up DP solution

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int decode_count1(const vector<int>& code, int n);
int decode_count2(const vector<int>& code, int n, int dp[]);
int decode_count3(const vector<int>& code, int dp[]);
void make_table(int dp[], const vector<int>& code);

int main()
{
	vector<int> code1 = {2, 0, 4, 1, 1};
	cout << decode_count1(code1, 0) << "\n";
	
	int size = code1.size() + 1;
	int dp[size];
	// Only needed for decode_count2() (second solution)
	fill(dp, dp + size, -1);
	cout << decode_count2(code1, 0, dp) << "\n";
	
	// Only needed for decode_count3() (third solution)
	make_table(dp, code1);
	cout << decode_count3(code1, dp) << "\n";
	
	return 0;
}

int decode_count1(const vector<int>& code, int n)
{
	if(n >= code.size() - 1)
		return 1;
	
	// If current digit is zero, no single digit code possible
	if(code[n] == 0)
		return 0;
		
	int count = 0;
	// If double digit code is possible
	if(code[n] <= 2 && code[n + 1] <= 6)
		count = decode_count1(code, n + 2);
	
	count += decode_count1(code, n + 1);
	return count;
}

int decode_count2(const vector<int>& code, int n, int dp[])
{
	if(dp[n] >= 0)
		return dp[n];

	if(n >= code.size() - 1) {
		dp[n] = 1;
		return dp[n];
	}
	
	// If current digit is zero, no single digit code possible
	if(code[n] == 0) {
		dp[n] = 0;
		return dp[n];
	}
	
	int count = 0;
	// If double digit code is possible
	if(code[n] <= 2 && code[n + 1] <= 6)
		count = decode_count2(code, n + 2, dp);
	
	count += decode_count2(code, n + 1, dp);
	dp[n] = count;
	return dp[n];
}

int decode_count3(const vector<int>& code, int dp[])
{
	return dp[0];
}

void make_table(int dp[], const vector<int>& code)
{
	int size = code.size();
	dp[size] = 1;
	dp[size - 1] = 1;
	for(int i = size - 2; i >= 0; i--) {
		dp[i] = 0;
		// If current digit is zero, no single digit code possible
		if(code[i] == 0)
			continue;
		// If double digit code is possible
		if(code[i] <= 2 && code[i + 1] <= 6) {
			dp[i] = dp[i + 2];
		}
		
		dp[i] += dp[i + 1];
	}
}