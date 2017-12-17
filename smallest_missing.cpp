// Given an array of integers, find the smallest missing positive integer in linear time and
// constant space. You can modify the input array in-place.

// For example,
// Input - [3, 4, -1, 1]
// Output - 2
// Input [1, 2, 0]
// Output - 3

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

int smallest_missing(vector<int>& a);
int segregate(vector<int>& a);

int main()
{
	vector<int> a = {1, 2, 5, 4, 1, 0, -1, 20};
	int result = smallest_missing(a);
	cout << result << "\n";
	return 0;
}

int smallest_missing(vector<int>& a)
{
	int n = segregate(a);
	
	for(int i = 0; i < n; i++) {
		int index = abs(a[i]) - 1;
		if(index < n && a[index] > 0)
			a[index] = -a[index];
	}

	for(int i = 0; i < n; i++) {
		if(a[i] > 0) {
			return i + 1;
		}
	}
	
	return n + 1;
}

int segregate(vector<int>& a)
{
	int j = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] > 0) {
			if(i != j)
				swap(a[i], a[j]);
			j++;
		}
	}
	return j;
}