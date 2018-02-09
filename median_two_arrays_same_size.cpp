// Find the median of two sorted arrays of same size
// For example,
// Input -
// A = {1, 2} B = {3, 4}
// Output - (2 + 3) / 2 = 2.5

// 1. Naive approach. Merge the two arrays, then find median. Time - O(N), Space - O(N).
// 2. Find elements that will be at middle on merging. Time - O(N), Space - O(1).
// 3. Divide and conquer solution. Time - O(LogN), Space - O(1).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

float median1(const vector<int>& a, const vector<int>& b);
float median2(const vector<int>& a, const vector<int>& b);
float median3(const vector<int>& a, const vector<int>& b);
float median_rec(const vector<int>& a, const vector<int>& b, int beg_a, int end_a, int beg_b,
	int end_b, int size);
float median_array(const vector<int>& a, int beg, int end, int size);

int main()
{
	// Ans - (2 + 3) / 2 = 2.5
	vector<int> a1 = {1, 2};
	vector<int> b1 = {3, 4};
	
	// Ans - (15 + 17) / 2 = 16
	vector<int> a2 = {1, 12, 15, 26, 38};
	vector<int> b2 = {2, 13, 17, 30, 45};
	
	vector<int> a3 = {1, 2, 3, 6};
	vector<int> b3 = {4, 6, 8, 10};
	
	cout << median1(a1, b1) << "\n";
	cout << median1(a2, b2) << "\n";
	cout << median1(a3, b3) << "\n";
	
	cout << median2(a1, b1) << "\n";
	cout << median2(a2, b2) << "\n";
	cout << median2(a3, b3) << "\n";
	
	cout << median3(a1, b1) << "\n";
	cout << median3(a2, b2) << "\n";
	cout << median3(a3, b3) << "\n";
	
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

float median2(const vector<int>& a, const vector<int>& b)
{
	int size = a.size();
	int i = 0, j = 0;
	int first = 0, second = 0;
	for(int count = 0; count <= size; count++) {
		first = second;
		
		if(i == size) {
			second = b[0];
			break;
		}
		if(j == size) {
			second = a[0];
			break;
		}
		
		if(a[i] < b[j])
			second = a[i++];
		else
			second = b[j++];
	}
	
	float median = (first + second) / 2.0;
	return median;
}

float median3(const vector<int>& a, const vector<int>& b)
{
	int size = a.size();
	return median_rec(a, b, 0, size - 1, 0, size - 1, size);
}

float median_rec(const vector<int>& a, const vector<int>& b, int beg_a, int end_a, int beg_b,
	int end_b, int size)
{
	if(size == 2) {
		return ( max(a[beg_a], b[beg_b]) + min(a[end_a], b[end_b]) ) / 2.0;
	}
	
	float median_a = median_array(a, beg_a, end_a, size);
	float median_b = median_array(b, beg_b, end_b, size);
	
	if(median_a == median_b)
		return median_a;
		
	int new_size = size / 2;
		
	if(median_a < median_b) {
		int new_beg_a = beg_a + new_size;
		int new_end_b = end_b - new_size;
		if(size % 2 == 0)
			return median_rec(a, b, new_beg_a, end_a, beg_b, new_end_b, new_size);

		return median_rec(a, b, new_beg_a, end_a, beg_b, new_end_b, new_size + 1);
	}
	
	int new_beg_b = beg_b + new_size;
	int new_end_a = end_a - new_size;
	if(size % 2 == 0)
		return median_rec(a, b, beg_a, new_end_a, new_beg_b, end_b, new_size);
		
	return median_rec(a, b, beg_a, new_end_a, new_beg_b, end_b, new_size + 1);
}

float median_array(const vector<int>& a, int beg, int end, int size)
{
	if(size % 2 == 0)
		return (a[beg + size/2] + a[beg + size/2 - 1]) / 2;
	
	return a[beg + size/2];
}