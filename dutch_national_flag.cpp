// Given an array containing only 0’s, 1’s and 2’s, sort the array in linear time and using
// constant space.
// For example,
// Input - 1, 1, 0, 2, 0, 1
// Output - 0, 0, 1, 1, 1, 2

// 1. Count occurrences of 0, 1 and 2. Then put them in correct order. Time - O(N), Space - O(1).
// 2. Use three way partitioning. Time - O(N), Space - O(1).

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void linear_sort1(vector<int>& a)
{
	int count[3] = {0};
	for(int i = 0; i < a.size(); i++) {
		count[a[i]]++;
	}
	
	int index = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < count[i]; j++)
			a[index++] = i;
	}
}

void linear_sort2(vector<int>& a)
{
	int low = 0, mid = 0, high = a.size() - 1;
	while(mid <= high) {
		if(a[mid] == 0) {
			swap(a[mid], a[low]);
			low++;
			mid++;
		}
		else if(a[mid] == 1) {
			mid++;
		}
		else {
			swap(a[mid], a[high]);
			high--;
		}
	}
}

int main()
{
	vector<int> a = {1, 2, 1, 0, 2, 0, 1};
	linear_sort2(a);
	for(auto& i: a)
		cout << i << " ";
	cout << "\n";
	return 0;
}