// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range
// from 1 to 3999.
// https://leetcode.com/problems/roman-to-integer/description/
// For example,
// Input - "XXVII"
// Output - 27

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int roman_to_int(const string& s)
{
	unordered_map<char, int> value = {
		{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
	};
	
	int size = s.size();
	int number = 0;
	for(int i = 1; i < size; i++) {
		int prev = value[s[i - 1]];
		int cur = value[s[i]];
		if(cur <= prev)
			number += prev;
		else
			number -= prev;
	}
	
	number += value[s[size - 1]];
	return number;
}

int main()
{
	// Ans: 1776
	string s1 = "MDCCLXXVI";
	// Ans: 498
	string s2 = "CDXCVIII";
	
	cout << roman_to_int(s1) << "\n";
	cout << roman_to_int(s2) << "\n";
	
	return 0;
}