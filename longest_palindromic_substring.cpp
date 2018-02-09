// Given a string s, find the longest palindromic substring in s
// https://leetcode.com/problems/longest-palindromic-substring/description/
// For example-
// Input - "cbbd"
// Output - "bb"

// 1. Naive approach. For every substring check if it is a palindrome or not. Time - O(N^3),
// Space - O(1).

#include <iostream>
#include <string>
using namespace std;

string longest_palindromic_substring1(const string& s);
bool is_palindrome(const string& s, int start, int end);

int main()
{
	string s1 = "abcdeabcbadbde";
	string s2 = "abbaaaaadc";
	cout << longest_palindromic_substring1(s1) << "\n";
	cout << longest_palindromic_substring1(s2) << "\n";

	return 0;
}

string longest_palindromic_substring1(const string& s)
{
	int max_len = 0, max_i = -1;
	int size = s.size();
	for(int i = 0; i < size; i++) {
		for(int j = i; j < size; j++) {
			if(!is_palindrome(s, i, j))
				continue;
			
			int len = j - i + 1;
			if(len > max_len) {
				max_len = len;
				max_i = i;
			}
		}
	}
	
	return s.substr(max_i, max_len);
}

bool is_palindrome(const string& s, int start, int end)
{
	if(end - start == 0)
		return true;

	while(start < end) {
		if(s[start] != s[end])
			return false;
		
		start++;
		end--;
	}
	
	return true;
}