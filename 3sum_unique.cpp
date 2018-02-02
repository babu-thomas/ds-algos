// Given an unsorted array of integers, find all UNIQUE triplets in the array which gives the sum
// of zero.
// For example,
// Input -
//	-2, 0, 0, 2, 2
// Output -
//	-2, 0, 2

// 1. Sort then use two pointer approach, skipping duplicates. Time - O(N^2), Space - O(1).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void three_sum_unique(vector<int> a)
{
	sort(a.begin(), a.end());
	int size = a.size();
	bool found = false;
	for(int i = 0; i < size - 2; i++) {
		// Skip duplicates of first number
		if(i > 0 && a[i] == a[i - 1])
			continue;
			
		int first = a[i];
		int left = i + 1;
		int right = size - 1;
		while(left < right) {
			int second = a[left];
			int third = a[right];
			int sum = first + second + third;
			if(sum == 0) {
				found = true;
				cout << first << ", " << second << ", " << third << "\n";
				// Skip duplicates of second number
				while(left < right && a[left] == second)
					left++;
				// Skip duplicates of third number
				while(left < right && a[right] == third)
					right--;
			}
			else if(sum < 0) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	
	if(!found)
		cout << "No triplet with zero sum" << "\n";
}

int main()
{
	// Ans - (-1, -1, 2), (-1, 0, 1)
	vector<int> a1 = {-1, 0, 1, 2, -1, -4};
	
	// Ans - (-2, 0, 2)
	vector<int> a2 = {-2, 0, 0, 2, 2};
	
	// Ans - (-4, -2, 6), (-4, 0, 4), (-4, 1, 3), (-4, 2, 2), (-2, -2, 4), (-2, 0, 2)
	vector<int> a3 = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
	
	three_sum_unique(a1);
	cout << "\n";
	three_sum_unique(a2);
	cout << "\n";
	three_sum_unique(a3);
	return 0;
}