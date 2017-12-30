// Given a sorted array of positive integers, rearrange the array alternately i.e first element
// should be maximum value, second minimum value, third second max, fourth second min and so on.
// For example,
// Input - 1, 2, 3, 4
// Output - 4, 1, 3, 2
// Input - 1, 2, 3, 4, 5
// Output - 5, 1, 4, 2, 3

// 1. Solution using two pointers and extra space. Time - O(N), Space - O(N).
// 2. Solution using base changing to store 2 numbers at one place. Time - O(N), Space - O(1).

#include <iostream>
#include <vector>
using namespace std;

vector<int> max_min1(const vector<int>& a)
{
	int n = a.size();
	vector<int> result(n);
	int left = 0, right = n - 1;
	for(int i = 0; i <= n - 2; i += 2) {
		if(left >= right)
			break;
		result[i] = a[right];
		result[i + 1] = a[left];
		right--;
		left++;
	}
	// If odd number of elements, copy last remaining element
	if(left == right)
		result[n - 1] = a[right];
	
	return result;
}

void max_min2(vector<int>& a)
{
	int n = a.size();
	int base = a[n - 1] + 1;
	int min_idx = 0, max_idx = n - 1;
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) {
			a[i] = (a[max_idx] % base) * base + a[i];
			max_idx--;
		}
		else {
			a[i] = (a[min_idx] % base) * base + a[i];
			min_idx++;
		}
	}
	for(int i = 0; i < n; i++)
		a[i] = a[i] / base;
}

void print(const vector<int>& a)
{
	for(auto &i: a)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
	vector<int> a2 = {1, 2, 3, 4, 5, 6};

	print(a1);
	print(max_min1(a1));
	max_min2(a1);
	print(a1);
	print(a2);
	print(max_min1(a2));
	max_min2(a2);
	print(a2);

	return 0;
}