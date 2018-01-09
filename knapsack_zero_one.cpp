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

int main()
{
	vector<item> items = {{1, 6}, {2, 10}, {3, 12}};
	cout << knapsack1(items, 5) << "\n";
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