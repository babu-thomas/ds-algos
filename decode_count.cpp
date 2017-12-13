// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it
// can be decoded.

// For example,
// Input -  111
// Output - 3, since it could be decoded as 'aaa, 'ka', and 'ak'.

// 1. Solution using recursion. Exponential time complexity.
// 2. Top down DP solution
// 3. Bottom up DP solution

#include <iostream>
#include <vector>
using namespace std;

int decode_count1(const vector<int>& code, int n);

int main()
{
	vector<int> code = {1, 0, 2, 2, 3};
	cout << decode_count1(code, 0) << "\n";
	return 0;
}

int decode_count1(const vector<int>& code, int n)
{
	if(n >= code.size() - 1)
		return 1;
	
	// If current digit is zero, no single digit code possible
	if(code[n] == 0)
		return 0;
		
	int count = 0;
	// If double digit code is possible
	if(code[n] <= 2 && code[n + 1] <= 6)
		count = decode_count1(code, n + 2);
	
	count += decode_count1(code, n + 1);
	return count;
}