// Implement wildcard pattern matching with support for '?' and '*'.
// '?' matches any single character.
// '*' matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
// https://leetcode.com/problems/wildcard-matching/description/
// http://www.techiedelight.com/wildcard-pattern-matching/
// For example,
// Input - string = "aba", pattern = "?ba*"
// Output - true
// Input - string = "bac", pattern = "?ba*"
// Output - false

// 1. Recursive solution. Exponential time complexity.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool is_match(const string& s, const string& pattern);
bool rec(const string& s, const string& pattern, int s_idx, int p_idx);

int main()
{
	string s = "baaab";
	// string s = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	vector<string> patterns = {
		"ba*****ab", "ba*ab", "a*ab", "a*****ab", "*a*****ab", "ba*ab****", "****", "*", "aa?ab",
		"b*b", "a*a", "baaabab", "?baaabab", "*baaaba*", "ba", "*****ba*****ab", "baaab*c"
	};
	
	// vector<string> patterns = {
	// 	"b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
	// };
	
	cout << "String: " << s << "\nPatterns:\n";
	for(auto& p: patterns)
		cout << p << " : " << (is_match(s, p) ? "true" : "false") << "\n";
	
	return 0;
}

bool is_match(const string& s, const string& pattern)
{
	return rec(s, pattern, 0, 0);
}

bool rec(const string& s, const string& pattern, int s_idx, int p_idx)
{
	// If string and pattern both end, its a match
	if(s_idx == s.size() && p_idx == pattern.size())
		return true;
	
	// If only pattern has ended, there is no match	
	if(p_idx == pattern.size())
		return false;
	
	// If only string has ended, its a match if all remaining characters in pattern are "*"
	if(s_idx == s.size()) {
		while(p_idx < pattern.size() && pattern[p_idx] == '*')
			p_idx++;
		
		return p_idx == pattern.size();
	}
	
	// If '?', match one character from string
	if(pattern[p_idx] == '?')
		return rec(s, pattern, s_idx + 1, p_idx + 1);
		
	if(pattern[p_idx] == '*') {
		// For consecutive stars, skip to last occurrence.
		while(pattern[p_idx + 1] == '*' && p_idx + 1 < pattern.size())
			p_idx++;
		
		// Match no characters or 1 character
		return rec(s, pattern, s_idx, p_idx + 1) || rec(s, pattern, s_idx + 1, p_idx);
	}
	
	// Not a wildcard, match directly
	return (s[s_idx] == pattern[p_idx]) && rec(s, pattern, s_idx + 1, p_idx + 1);
}