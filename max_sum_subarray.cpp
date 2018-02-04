// Given an array of integers, find contiguous subarray within it which has the largest sum.
// For example,
// Input -
//	-2, -5, 6, -2, -3, 1, 5, -6
// Output -
//	7 (The subarray is 6, -2, -3, 1, 5)

// 1. Naive solution. Sum all contiguous subarrays and return the max sum.
//    Time - O(N^2), Space - O(1).
// 2. Divide and conquer solution. Time - O(N.LogN), Space - O(1).

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int max_subarray_sum1(const vector<int>& a);
int max_subarray_sum2(const vector<int>& a);
int max_subarray_sum_rec(const vector<int>& a, int left, int right);
int max_subarray_cross_sum(const vector<int>& a, int left, int mid, int right);

int main()
{
	vector<int> a = {-2, -5, 6, -2, -3, 1, 5, -6};
	cout << max_subarray_sum1(a) << "\n";
	cout << max_subarray_sum2(a) << "\n";
	return 0;
}

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

int max_subarray_sum2(const vector<int>& a)
{
	return max_subarray_sum_rec(a, 0, a.size() - 1);
}

int max_subarray_sum_rec(const vector<int>& a, int left, int right)
{
	if(left == right)
		return a[left];
	
	int mid = left + (right - left) / 2;
	// Max subarray sum such that all elements are in the left half
	int left_sum = max_subarray_sum_rec(a, left, mid);
	// Max subarray sum such that all elements are in the right half
	int right_sum = max_subarray_sum_rec(a, mid + 1, right);
	// Max subarray sum containing elements from both halves
	int cross_sum = max_subarray_cross_sum(a, left, mid, right);
	
	return max(left_sum, max(cross_sum, right_sum));
}

int max_subarray_cross_sum(const vector<int>& a, int left, int mid, int right)
{
	// Max suffix sum of left half
	int left_max = numeric_limits<int>::min();
	int sum = 0;
	for(int i = mid; i >= left; i--) {
		sum += a[i];
		left_max = max(left_max, sum);
	}
	
	// Max prefix sum of right half
	int right_max = numeric_limits<int>::min();
	sum = 0;
	for(int i = mid + 1; i <= right; i++) {
		sum += a[i];
		right_max = max(right_max, sum);
	}
	
	return left_max + right_max;
}