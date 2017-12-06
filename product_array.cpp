// Given an array of integers, return a new array such that each element at index i of the new array
// is the product of all the numbers in the original array except the one at i.

// For example,
// Input - [1, 2, 3, 4, 5]
// Expected output - [120, 60, 40, 30, 24]

// 1. Solution using division in O(N) time.
// 2. Solution without using division and in time - O(N), space - O(N)
// 3. Solve it without using division and in time - O(N), space - O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> product_array1(const vector<int>& input)
{
	int product = 1;
	for(auto &i: input)
		product *= i;
	vector<int> result(input.size());
	for(int i = 0; i < result.size(); i++)
		result[i] = product / input[i];
	return result;
}

vector<int> product_array2(const vector<int>& input)
{
	vector<int> left(input.size());
	vector<int> right(input.size());
	vector<int> result(input.size());
	
	int product = 1;
	for(int i = 0; i < left.size(); i++) {
		left[i] = product;
		product *= input[i];
	}
	
	product = 1;
	for(int i = right.size() - 1; i >= 0; i--) {
		right[i] = product;
		product *= input[i];
	}
	
	for(int i = 0; i < result.size(); i++)
		result[i] = left[i] * right[i];
	
	return result;
}

vector<int> product_array3(const vector<int>& input)
{
	vector<int> result(input.size());
	int product = 1;
	for(int i = 0; i < result.size(); i++) {
		result[i] = product;
		product *= input[i];
	}
	product = 1;
	for(int i = result.size() - 1; i >= 0; i--) {
		result[i] *= product;
		product *= input[i];
	}
	return result;
}

int main()
{
	vector<int> input = {1, 2, 3, 4, 5};
	vector<int> result1 = product_array1(input);
	for(auto &i : result1)
		cout << i << " ";
	cout << "\n";
	
	vector<int> result2 = product_array2(input);
	for(auto &i : result2)
		cout << i << " ";
	cout << "\n";
	
	vector<int> result3 = product_array3(input);
	for(auto &i : result3)
		cout << i << " ";
	cout << "\n";
	return 0;
}