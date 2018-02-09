// Given an unsorted array of integers, find a pair with given sum.
// https://leetcode.com/problems/two-sum/description/
// For example,
// Input - 8, 7, 2, 1 and sum = 10
// Output - 0, 2 (Indices of 8 and 2)

// 1. Naive solution. Try all possible pairs. Time - O(N^2), Space - O(1).
// 2. Use Hash table. Time - O(N), Space - O(N).

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void two_sum1(vector<int> a, int target)
{
	int size = a.size();
	bool pair_found = false;
	for(int i = 0; i < size - 1; i++) {
		for(int j = i + 1; j < size; j++) {
			int sum = a[i] + a[j];
			if(sum == target) {
				pair_found = true;
				cout << i << ", " << j << "\n";
			}
		}
	}
	
	if(!pair_found)
		cout << "No pair with given sum" << "\n";
}

void two_sum2(vector<int> a, int target)
{
	unordered_map<int, int> pairs;
	bool pair_found = false;
	for(int i = 0; i < a.size(); i++) {
		int this_pair = a[i];
		int other_pair = target - this_pair;
		if(pairs.count(other_pair) > 0) {
			pair_found = true;
			cout << pairs[other_pair] << ", " << i << "\n";
		}
		pairs[this_pair] = i;
	}
	
	if(!pair_found)
		cout << "No pair with given sum" << "\n";
}

int main()
{
	vector<int> a = {8, 7, 2, 5, 3, 1};
	int target1 = 10;
	int target2 = 16;
	two_sum1(a, target1);
	two_sum1(a, target2);
	two_sum2(a, target1);
	two_sum2(a, target2);
	return 0;
}