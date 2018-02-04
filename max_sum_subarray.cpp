// Given an array of integers, find contiguous subarray within it which has the largest sum.
// For example,
// Input -
//	-2, -5, 6, -2, -3, 1, 5, -6
// Output -
//	7 (The subarray is 6, -2, -3, 1, 5)

// 1. Naive solution. Sum all contiguous subarrays and return the max sum.
//    Time - O(N^2), Space - O(1).

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int max_subarray_sum1(const vector<int>& a)
{
	int size = a.size();
	int max_sum = numeric_limits<int>::min();
	for(int i = 0; i < size; i++) {
		int sum = 0;
		for(int j = i; j < size; j++) {
			sum += a[j];
			max_sum = max(max_sum, sum);
		}
	}
	return max_sum;
}

int main()
{
	vector<int> a = {-2, -5, 6, -2, -3, 1, 5, -6};
	cout << max_subarray_sum1(a) << "\n";
	return 0;
}