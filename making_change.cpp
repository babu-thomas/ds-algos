// Given a positive integer representing an amount and a set of coins, write a function to compute
// the minimum number of coins required to make that amount of change.
// Bonus: Print all possible ways to make that change.

// 1. Recursive solution. Exponential time complexity.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int make_change(const vector<int>& coins, int amount, stack<int>& selected);
void print_stack(stack<int> s);

int main()
{
	vector<int> coins = {10, 6, 1};
	stack<int> selected;
	cout << make_change(coins, 12, selected) << "\n";
	return 0;
}

int make_change(const vector<int>& coins, int amount, stack<int>& selected)
{
	if(amount == 0) {
		print_stack(selected);
		return 0;
	}
	
	int min_coins = amount + 1;
	for(auto& c : coins) {
		if(amount - c >= 0) {
			selected.push(c);
			min_coins = min(min_coins, make_change(coins, amount - c, selected));
			selected.pop();
		}
	}
	
	return min_coins + 1;
}

void print_stack(stack<int> s)
{
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}