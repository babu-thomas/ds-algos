// Given a string, find the length of the longest substring without repeating characters
// For example,
// Input - "pwwkew"
// Output - 3 (The substring "wke")

// 1. Naive solution. Check every substring for uniqueness. Time - O(N^3), Space - O(S). S is the
// size of the alphabet.
// 2. Sliding window solution. Time - O(N), Space - O(S). S is the size of the alphabet.

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longest_non_repeating_substring1(const string& s);
bool is_unique(const string& s, int start, int end);
int longest_non_repeating_substring2(const string& s);

int main()
{
	string s1 = "pwwkew";
	string s2 = "abcabcbb";
	string s3 = "bbbbb";
	cout << longest_non_repeating_substring1(s1) << "\n"
		 << longest_non_repeating_substring1(s2) << "\n"
		 << longest_non_repeating_substring1(s3) << "\n";
		 
	cout << longest_non_repeating_substring2(s1) << "\n"
		 << longest_non_repeating_substring2(s2) << "\n"
		 << longest_non_repeating_substring2(s3) << "\n";

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
	unordered_map<int, bool> found;
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
	int i = 0, j = 0, max_len = 0;
	unordered_map<int, bool> found;
	while(i < size && j < size) {
		// If jth character not already present, extend the substring by adding it
		if(!found[s[j]]) {
			found[s[j]] = true;
			max_len = max(max_len, j - i + 1);
			j++;
		}
		else {
			// Remove ith character or the first character from current substring
			found[s[i]] = false;
			i++;
		}
	}
	
	return max_len;
}