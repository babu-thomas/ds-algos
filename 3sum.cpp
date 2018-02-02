// Given an unsorted array of integers, find all triplets in the array which gives the sum
// of zero.
// For example,
// Input - -1, 0, 1, 2, -1, -4
// Output -
//	-1, 0, 1
//	-1, -1, 2

// 1. Naive solution. Try all possible triplets. Time - O(N^3), Space - O(1).
// 2. Use Hash Table. Time - O(N^2), Space - O(N).
// 3. Sort the array then use two pointer approach. Time - O(N^2), Space - O(1).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void three_sum1(vector<int> a)
{
	int size = a.size();
	bool found = false;
	for(int i = 0; i < size - 2; i++) {
		for(int j = i + 1; j < size - 1; j++) {
			for(int k = j + 1; k < size; k++) {
				if(a[i] + a[j] + a[k] == 0) {
					found = true;
					cout << a[i] << ", " << a[j] << ", " << a[k] << "\n";
				}
			}
		}
	}
	
	if(!found)
		cout << "No triplet with zero sum" << "\n";
}

void three_sum2(vector<int> a)
{
	int size = a.size();
	bool found = false;
	for(int i = 0; i < size - 2; i++) {
		int first = a[i];
		unordered_map<int, bool> pairs;
		for(int j = i + 1; j < size; j++) {
			int second = a[j];
			int third = -(first + second);
			if(pairs.count(third) > 0) {
				found = true;
				cout << first << ", " << second << ", " << third << "\n";
			}
			pairs[second] = true;
		}
	}
	
	if(!found)
		cout << "No triplet with zero sum" << "\n";
}

void three_sum3(vector<int> a)
{
	sort(a.begin(), a.end());
	int size = a.size();
	bool found = false;
	for(int i = 0; i < size - 2; i++) {
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
				left++;
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
	vector<int> a = {-1, 0, 1, 2, -1, -4};
	three_sum1(a);
	cout << "\n";
	three_sum2(a);
	cout << "\n";
	three_sum3(a);
	return 0;
}