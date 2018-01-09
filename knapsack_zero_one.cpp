// Given weights and values of n items, put these items in a knapsack of capacity W to get the
// maximum total value in the knapsack.
// For example,
// Inputs -
//	Weights - 1, 2, 3
//	Values - 6, 10, 12
//	Capacity - 5
// Output - 22

// 1. Recursive solution. For each item, calculate value if its included and not included.
//	  Exponential time complexity.
// 2. DP solution. Time - O(N * W), Space - O(N * W).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
	int weight;
	int value;
};

int knapsack1(const vector<item>& items, int capacity);
int rec(const vector<item>& items, int capacity, int index);
int knapsack2(const vector<item>& items, int capacity);

int main()
{
	vector<item> items = {{1, 6}, {2, 10}, {3, 12}};
	cout << knapsack1(items, 5) << "\n";
	cout << knapsack2(items, 5) << "\n";
	return 0;
}

int knapsack1(const vector<item>& items, int capacity)
{
	int n = items.size();
	return rec(items, capacity, n - 1);
}

int rec(const vector<item>& items, int capacity, int index)
{
	if(index < 0 || capacity == 0)
		return 0;
	
	int include_value = 0, exclude_value = 0;
	int weight = items[index].weight;
	int value = items[index].value;
	if(capacity >= weight)
		include_value = value + rec(items, capacity - weight, index - 1);
	
	exclude_value = rec(items, capacity, index - 1);
	return max(include_value, exclude_value);
}

int knapsack2(const vector<item>& items, int capacity)
{
	int n = items.size();
	int dp[n][capacity + 1];
	
	// Zero value for zero capacity
	for(int i = 0; i < n; i++)
		dp[i][0] = 0;
		
	// If only first item is present
	int weight = items[0].weight;
	int value = items[0].value;
	for(int j = 1; j <= capacity; j++) {
		if(weight <= j)
			dp[0][j] = value;
		else
			dp[0][j] = 0;
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= capacity; j++) {
			weight = items[i].weight;
			value = items[i].value;
			if(weight <= j)
				dp[i][j] = max(value + dp[i - 1][j - weight], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	return dp[n - 1][capacity];
}