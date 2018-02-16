// Given n pairs of parentheses, write a function to generate all combinations of well-formed
// parentheses.
// https://leetcode.com/problems/generate-parentheses/description/
// https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
// For example,
// Input - 2
// Output - "(())", "()()"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> valid_parens(int count);
void rec(int count, int open, int closed, string current, vector<string>& result);

int main()
{
	vector<string> result1 = valid_parens(2);
	vector<string> result2 = valid_parens(3);
	vector<string> result3 = valid_parens(4);
	
	for(auto& s: result1)
		cout << s << " ";
	cout << "\n\n";
	
	for(auto& s: result2)
		cout << s << " ";
	cout << "\n\n";
	
	for(auto& s: result3)
		cout << s << " ";
	cout << "\n\n";
	
	return 0;
}

vector<string> valid_parens(int count)
{
	vector<string> result;
	
	if(n == 0)
		return result;
	
	rec(count, 0, 0, "", result);
	return result;
}

void rec(int count, int open, int closed, string current, vector<string>& result)
{
	if(closed == count) {
		result.push_back(current);
		return;
	}
	
	if(open > closed)
		rec(count, open, closed + 1, current + ")", result);
	
	if(open < count)
		rec(count, open + 1, closed, current + "(", result);
}