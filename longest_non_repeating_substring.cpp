// Given a string, find the length of the longest substring without repeating characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// For example,
// Input - "pwwkew"
// Output - 3 (The substring "wke" or "kew")

// 1. Naive solution. Check every substring for uniqueness. Time - O(N^3), Space - O(S). S is the
// size of the alphabet.
// 2. Sliding window solution. Time - O(N), Space - O(S). S is the size of the alphabet.
// 3. Optimized sliding window. Time - O(N), Space - O(N). S is the size of the alphabet.

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longest_non_repeating_substring1(const string& s);
bool is_unique(const string& s, int start, int end);
int longest_non_repeating_substring2(const string& s);
int longest_non_repeating_substring3(const string& s);

int main()
{
	string s1 = "pwwkpew";
	string s2 = "abcabcbb";
	string s3 = "bbbbb";
	cout << longest_non_repeating_substring1(s1) << "\n"
		 << longest_non_repeating_substring1(s2) << "\n"
		 << longest_non_repeating_substring1(s3) << "\n";
		 
	cout << longest_non_repeating_substring2(s1) << "\n"
		 << longest_non_repeating_substring2(s2) << "\n"
		 << longest_non_repeating_substring2(s3) << "\n";
		 
	cout << longest_non_repeating_substring3(s1) << "\n"
		 << longest_non_repeating_substring3(s2) << "\n"
		 << longest_non_repeating_substring3(s3) << "\n";

	return 0;
}

int longest_non_repeating_substring1(const string& s)
{
	int max_len = 0;
	for(int i = 0; i < s.size(); i++) {
		for(int j = i; j < s.size(); j++) {
			if(is_unique(s, i, j)) {
				max_len = max(max_len, j - i + 1);
			}
		}
	}
	
	return max_len;
}

bool is_unique(const string& s, int start, int end)
{
	unordered_map<char, bool> found;
	for(int i = start; i <= end; i++) {
		if(found.count(s[i]) > 0)
			return false;
		
		found[s[i]] = true;
	}
	
	return true;
}

int longest_non_repeating_substring2(const string& s)
{
	int size = s.size();
	int start = 0, end = 0, max_len = 0;
	unordered_map<char, bool> found;
	while(start < size && end < size) {
		// If end character not already present, extend the substring by adding it
		if(!found[s[end]]) {
			found[s[end]] = true;
			max_len = max(max_len, end - start + 1);
			end++;
		}
		else {
			// Remove first character from current substring
			found[s[start]] = false;
			start++;
		}
	}
	
	return max_len;
}

int longest_non_repeating_substring3(const string& s)
{
	int size = s.size();
	int max_len = 0;
	unordered_map<char, int> found;
	
	for(int start = 0, end = 0; end < size; end++) {
		// If end character already present in substring, adjust start index to skip its
		// previous occurrence.
		// We take max because we are not deleting entries from the found map when start is updated.
		// If start is already after the index stored in the map, then we don't update it.
		if(found.count(s[end]) > 0)
			start = max(found[s[end]] + 1, start);
		
		max_len	= max(max_len, end - start + 1);
		found[s[end]] = end;
	}
	
	return max_len;
}