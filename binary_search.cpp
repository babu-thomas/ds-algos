// Binary search and "Binary Stride" variant of binary search
// https://www.topcoder.com/blog/binary-stride-a-variant-on-binary-search/

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> a, int target)
{
	int size = a.size();
	int low = 0;
	int high = size - 1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(a[mid] == target)
			return mid;
		
		if(a[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	return -1;
}

int binary_stride(vector<int> a, int target)
{
	int size = a.size();
	int start = 0;
	for(int stride = size/2; stride >= 1; stride /= 2) {
		while(start + stride < size && a[start + stride] <= target) {
			start += stride;
		}
	}
	
	if(a[start] == target)
		return start;
	
	return -1;
}

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	vector<int> b = {1, 3, 3};
	cout << binary_search(a, 3) << "\n"
		 << binary_search(a, 6) << "\n"
		 << binary_search(b, 2) << "\n"
		 << binary_search(b, 3) << "\n";
		 
	cout << binary_stride(a, 3) << "\n"
		 << binary_stride(a, 6) << "\n"
		 << binary_stride(b, 2) << "\n"
		 << binary_stride(b, 3) << "\n";
	return 0;
}