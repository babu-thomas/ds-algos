// Given an array and a positive integer r, right rotate the array by r elements in linear time and
// constant space.
// For example,
// Input -  1, 2, 3, 4, 5 and r = 2
// Output - 4, 5, 1, 2, 3

// 1. Solution using temp array. Time - O(N), Space - O(r)

#include <iostream>
#include <vector>
using namespace std;

void rotate1(vector<int>& a, int r)
{
	int n = a.size();
	r = r % n;
	// Save last r elements
	vector<int> temp(a.end() - r, a.end());
	// Shift other elements
	for(int i = n - r - 1; i >= 0; i--)
		a[i + r] = a[i];
	// Put last r elements in the right place
	for(int i = 0; i < temp.size(); i++)
		a[i] = temp[i];
}

int main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6};
	rotate1(a, 10);
	for(auto &i: a)
		cout << i << " ";
	cout << "\n";
	return 0;
}