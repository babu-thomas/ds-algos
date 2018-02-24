// Find the median of two sorted arrays of different sizes S1 and S2.
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// https://www.youtube.com/watch?v=LPFhl65R7ww
// For example,
// Input -
// A = {1, 2} B = {3, 4, 5, 6}
// Output - (3 + 4) / 2 = 3.5

// 1. Binary search. Time - O(log(M)), where M = min(S1, S2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

float median(const vector<int>& a, const vector<int>& b);

int main()
{
	vector<vector<int>> arrays = {
		{2, 3, 17}, {1, 12, 15, 26, 28}, {1, 3, 8, 9, 15}, {7, 11, 18, 19, 21, 25},
		{23, 26, 31, 35}, {3, 5, 7, 9, 11, 16}
	};
	
	for(int i = 1; i < arrays.size(); i++) {
		cout << median(arrays[i - 1], arrays[i]) << "\n"
			 << median(arrays[i], arrays[i - 1]) << "\n\n";
	}
	
	return 0;
}

float median(const vector<int>& a, const vector<int>& b)
{
	int size_a = a.size();
	int size_b = b.size();
	
	if(size_b < size_a)
		return median(b, a);
		
	int start = 0, end = size_a;
	while(start <= end) {
		int partition_a = (start + end + 1) / 2;
		int partition_b = (size_a + size_b) / 2 - partition_a;
		
		int left_max_a  = (partition_a == 0 ? numeric_limits<int>::min() : a[partition_a - 1]);
		int right_min_a = (partition_a == size_a ? numeric_limits<int>::max() : a[partition_a]);
		int left_max_b  = (partition_b == 0 ? numeric_limits<int>::min() : b[partition_b - 1]);
		int right_min_b = (partition_b == size_b ? numeric_limits<int>::max() : b[partition_b]);
		
		if(left_max_a <= right_min_b && left_max_b <= right_min_a) {
			// Found median
			if((size_a + size_b) % 2 != 0)
				return max(left_max_a, left_max_b);
			
			return (max(left_max_a, left_max_b) + min(right_min_a, right_min_b)) / 2.0;
		}
		else if(left_max_a > right_min_b) {
			// Move a's range to left
			end = partition_a - 1;
		}
		else {
			// Move a's range to right
			start = partition_a;
		}
	}
}