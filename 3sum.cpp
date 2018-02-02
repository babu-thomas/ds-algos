// Given an unsorted array of integers, find all unique triplets in the array which gives the sum
// of zero.
// For example,
// Input - -1, 0, 1, 2, -1, -4
// Output -
//	-1, 0, 1
//	-1, -1, 2

// 1. Naive solution. Try all possible triplets. Time - O(N^3), Space - O(1)

#include <iostream>
#include <vector>
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

int main()
{
	vector<int> a = {-1, 0, 1, 2, -1, -4};
	three_sum1(a);
	return 0;
}