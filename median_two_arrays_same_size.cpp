// Find the median of two sorted arrays of same size
// For example,
// Input -
// A = {1, 2} B = {3, 4}
// Output - (2 + 3) / 2 = 2.5

// 1. Naive approach. Merge the two arrays, then find median. Time - O(N), Space - O(N).

#include <iostream>
#include <vector>
using namespace std;

float median1(const vector<int>& a, const vector<int>& b);

int main()
{
	// Ans - (2 + 3) / 2 = 2.5
	vector<int> a1 = {1, 2};
	vector<int> b1 = {3, 4};
	
	// Ans - (15 + 17) / 2 = 16
	vector<int> a2 = {1, 12, 15, 26, 38};
	vector<int> b2 = {2, 13, 17, 30, 45};
	
	cout << median1(a1, b1) << "\n";
	cout << median1(a2, b2) << "\n";
	
	return 0;
}

float median1(const vector<int>& a, const vector<int>& b)
{
	int size = a.size();
	int m_size = size * 2;
	vector<int> merged(m_size);
	
	int i = 0, j = 0, k = 0;
	while(i < size && j < size) {
		if(a[i] < b[j])
			merged[k++] = a[i++];
		else
			merged[k++] = b[j++];
	}
	while(i < size)
		merged[k++] = a[i++];
	while(j < size)
		merged[k++] = b[j++];
		
	float median = (merged[size] + merged[size - 1]) / 2.0;

	return median;
}