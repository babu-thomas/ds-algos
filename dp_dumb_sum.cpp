// Question in below links
// https://www.codechef.com/DI17R162/problems/COUNTKID/
// https://ideone.com/US8Qdr
// Screenshots - https://i.imgur.com/QJj6xb2.png  https://i.imgur.com/SV13geQ.png

// 1. Solution using recursion. Exponential time complexity.
// 2. Top down DP Solution
// 3. Bottom up DP Solution

#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int ways1(int n);
int ways2(int n, int dp[]);
int ways3(int n, int dp[]);
void make_table(int dp[]);
int sum_mod(int a, int b);

int main()
{
	int dp[1001];
	
	// Only needed for ways2() (second solution)
	// std::fill(dp, dp+1001, -1);
	
	// Only needed for ways3() (third solution)
	make_table(dp);
	
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		cout << ways3(n, dp) << "\n";
	}
	return 0;
}

int ways1(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 2;
	if(n == 2)
		return 5;
	if(n == 3)
		return 13;
		
	int result =  sum_mod(sum_mod(2 * ways1(n-1), ways1(n-2)), ways1(n-3));
	return result;
}

int ways2(int n, int dp[])
{
	if(dp[n] >= 0)
		return dp[n];
	
	if(n == 0) {
		dp[n] = 0;
		return dp[n];
	}
	
	if(n == 1) {
		dp[n] = 2;
		return dp[n];
	}
	
	if(n == 2) {
		dp[n] = 5;
		return dp[n];
	}
	
	if(n == 3) {
		dp[n] = 13;
		return dp[n];
	}
	
	int result = sum_mod(sum_mod(2 * ways2(n-1, dp), ways2(n-2, dp)), ways2(n-3, dp));
	return result;
}

int ways3(int n, int dp[])
{
	return dp[n];
}

void make_table(int dp[])
{
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 5;
	dp[3] = 13;
	
	for(int i = 4; i <= 1000; i++) {
		dp[i] = sum_mod(sum_mod(2 * dp[i-1], dp[i-2]), dp[i-3]);
	}
}

int sum_mod(int a, int b)
{
	int result = (a % MOD + b % MOD) % MOD;
	return result;
}