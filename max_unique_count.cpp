// Given an unsorted array, find the maximum frequency of elements. If 2 or more elements appear
// with the maximum frequency, return -1.
// For example,
// Input - aaab
// Output - 3
// Input - aabb
// Output - -1

// 1. Naive solution. Time - O(N^2), Space - O(1).

#include <iostream>
#include <string>
using namespace std;

int max_unique_count1(const string& s)
{
	int size = s.size();
	int max_count = 0;
	bool is_repeat = false;
	
	for(int i = 0; i < size; i++) {
		int count = 1;
		for(int j = i + 1; j < size; j++) {
			if(s[i] == s[j])
				count++;
		}
		if(count > max_count) {
			max_count = count;
			is_repeat = false;
		}
		else if(count == max_count) {
			is_repeat = true;
		}
	}
	
	if(is_repeat)
		return -1;
		
	return max_count;
}

int main()
{
	string s1 = "aabb";
	string s2 = "abbc";
	string s3 = "aabbccc";
	
	cout << max_unique_count1(s1) << "\n"
		 << max_unique_count1(s2) << "\n"
		 << max_unique_count1(s3) << "\n";
	
	return 0;
}