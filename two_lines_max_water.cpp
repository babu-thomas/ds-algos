// Given an array A of non-negative integers, A[i] is the height of a vertical line at i on the x-axis.
// Find the max area of water that can be contained by two lines from A.
// https://leetcode.com/problems/container-with-most-water/description/
// For example,
// Input - 1, 5, 4, 3
// Output - 6 (on selecting 5 and 3)
// Explanation - 5 and 3 are 2 distance apart, so area will be:
// Base * Height = 2 * 3 = 6

// 1. Sliding window approach. Time - O(N), Space - O(1).

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_area(const vector<int>& a)
{
	int size = a.size();
	int max_area = 0, area = 0;
	int start = 0, end = size - 1;
	while(start < end) {
		if(a[start] < a[end]) {
			area = a[start] * (end - start);
			start++;
		}
		else {
			area = a[end] * (end - start);
			end--;
		}
		max_area = max(max_area, area);
	}
	
	return max_area;
}

int main()
{
	vector<int> a = {1, 5, 4, 3};
	cout << max_area(a) << "\n";
	return 0;
}