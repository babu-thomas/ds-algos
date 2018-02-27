// Implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// https://leetcode.com/problems/regular-expression-matching/description/

// 1. Recursive solution. Exponential time complexity.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_match(const string& s, const string& pattern);
bool rec(const string& s, const string& p, int s_idx, int p_idx);

int main()
{
	string p = "a.*b*c";
	vector<string> strings = {
		"abc", "adc", "ac", "adcbbbc", "adcbcbc", "bbc", "dc", "", "a"
	};
	
	for(auto& s: strings)
		cout << (is_match(s, p) ? "True" : "False") << "\n";
		
	cout << (is_match("aa", "a*") ? "True" : "False") << "\n";
	cout << (is_match("aab", "c*a*b") ? "True" : "False") << "\n";
	cout << (is_match("a", "ab*a") ? "True" : "False") << "\n";
	
	return 0;
}

bool is_match(const string& s, const string& pattern)
{
	return rec(s, pattern, s.size() - 1, pattern.size() - 1);
}

bool rec(const string& s, const string& p, int s_idx, int p_idx)
{
	// If string and pattern both end, its a match
	if(s_idx == -1 && p_idx == -1)
		return true;
	
	// If only pattern ends, not a match
	if(p_idx == -1)
		return false;
	
	// If only string ends, and all characters in pattern are of the form
	// "any letter followed by star" repeated, its a match
	if(s_idx == -1) {
		if(p_idx < 1 || p[p_idx] != '*')
			return false;
			
		return rec(s, p, s_idx, p_idx - 2);
	}
	
	if(p[p_idx] == '.' || p[p_idx] == s[s_idx])
		return rec(s, p, s_idx - 1, p_idx - 1);
	
	if(p[p_idx] == '*') {
		bool prev_dot_or_equal = p[p_idx - 1] == '.' || p[p_idx - 1] == s[s_idx];
		
		return prev_dot_or_equal && rec(s, p, s_idx - 1, p_idx) || rec(s, p, s_idx, p_idx - 2);
	}
	
	return false;
}