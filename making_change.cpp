// Given a positive integer representing an amount and a set of coins, write a function to compute
// the minimum number of coins required to make that amount of change.
// Bonus: Print all possible ways to make that change.

// 1. Recursive solution. Exponential time complexity.
// 2. DP solution. Time - O(C * N), Space - O(N), where C = number of coins, N = amount

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int make_change1(const vector<int>& coins, int amount, stack<int>& selected);
int make_change2(const vector<int>& coins, int amount);
void print_stack(stack<int> s);

int main()
{
	vector<int> coins = {10, 6, 1};
	stack<int> selected;
	cout << make_change1(coins, 12, selected) << "\n";
	cout << make_change2(coins, 12) << "\n";
	return 0;
}

int make_change1(const vector<int>& coins, int amount, stack<int>& selected)
{
	if(amount == 0) {
		// print_stack(selected);
		return 0;
	}
	
	int min_coins = amount + 1;
	for(auto& c : coins) {
		if(amount - c >= 0) {
			// selected.push(c);
			min_coins = min(min_coins, make_change1(coins, amount - c, selected));
			// selected.pop();
		}
	}
	
	return min_coins + 1;
}

int make_change2(const vector<int>& coins, int amount)
{
	int dp[amount + 1];
	dp[0] = 0;
	for(int i = 1; i <= amount; i++) {
		dp[i] = i + 1;
		for(int c = 0; c < coins.size(); c++) {
			int coin = coins[c];
			if(i - coin >= 0) {
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
	}
	
	return dp[amount];
}

void print_stack(stack<int> s)
{
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}