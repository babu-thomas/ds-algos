// Given an unsorted array of integers, find a pair with given sum.
// For example,
// Input - 8, 7, 2, 1 and sum = 10
// Output - 0, 2 (Indices of 8 and 2)

// 1. Naive solution. Try all possible pairs. Time - O(N^2), Space - O(1).

#include <iostream>
#include <vector>
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

int main()
{
	vector<int> a = {8, 7, 2, 5, 3, 1};
	int target = 10;
	two_sum1(a, target);
	return 0;
}