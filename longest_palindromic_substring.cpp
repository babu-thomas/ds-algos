// Given a string s, find the longest palindromic substring in s
// https://leetcode.com/problems/longest-palindromic-substring/description/
// For example-
// Input - "cbbd"
// Output - "bb"

// 1. Naive approach. For every substring check if it is a palindrome or not. Time - O(N^3),
// Space - O(1).
// 2. Expand palindrome from center. Time - O(N^2), Space - O(1).

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string longest_palindromic_substring1(const string& s);
bool is_palindrome(const string& s, int start, int end);
string longest_palindromic_substring2(const string& s);
int expand(const string& s, int before, int after);

int main()
{
	string s1 = "abcdeabcbadbde";
	string s2 = "abbaaaaadc";
	cout << longest_palindromic_substring1(s1) << "\n";
	cout << longest_palindromic_substring1(s2) << "\n";
	
	cout << longest_palindromic_substring2(s1) << "\n";
	cout << longest_palindromic_substring2(s2) << "\n";
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

string longest_palindromic_substring2(const string& s)
{
	int size = s.size();
	int start = 0, end = 0;
	int max_len = 0;
	for(int i = 0; i < size; i++) {
		int len1 = expand(s, i, i);
		int len2 = expand(s, i, i + 1);
		int len = max(len1, len2);
		if(len > max_len) {
			max_len = len;
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	
	return s.substr(start, max_len);
}

int expand(const string& s, int before, int after)
{
	int size = s.size();
	while(before >= 0 && after < size && s[before] == s[after]) {
		before--;
		after++;
	}
	
	return after - before - 1;
}