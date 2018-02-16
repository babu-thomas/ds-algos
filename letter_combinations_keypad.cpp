// Given a digit string, return all possible letter combinations that the number could represent.
// The digit to letters are mapped like on a old phone keypad.
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// https://www.geeksforgeeks.org/find-possible-words-phone-digits/
// For example,
// Input - "23"
// Output - "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

// 1. Recursive solution (DFS). Exponential time complexity.
// 2. Iterative solution (BFS). Exponential time complexity.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

using LetterMap = unordered_map<char, string>;

vector<string> letter_combinations1(string digits);
void rec(const string& digits, int index, string current, LetterMap& letters,
	vector<string>& result);
	
vector<string> letter_combinations2(string digits);

int main()
{
	vector<string> result1 = letter_combinations1("79");
	vector<string> result2 = letter_combinations2("79");
	
	for(auto& s : result1)
		cout << s << " ";
	cout << "\n\n";
	
	for(auto& s : result2)
		cout << s << " ";
	cout << "\n\n";
	
	return 0;
}

vector<string> letter_combinations1(string digits)
{
	vector<string> result;
	
	if(digits.empty())
		return result;
	
	LetterMap letters = {
		{'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', ""}
	};
	
	rec(digits, 0, "", letters, result);
	
	return result;
}

void rec(const string& digits, int index, string current, LetterMap& letters,
	vector<string>& result)
{
	if(index == digits.size()) {
		result.push_back(current);
		return;
	}
	
	if(digits[index] == '0' || digits[index] == '1')
		return;
	
	for(char& c : letters[digits[index]]) {
		current.push_back(c);
		rec(digits, index + 1, current, letters, result);
		current.pop_back();
	}
}

vector<string> letter_combinations2(string digits)
{
	vector<string> result;
	
	if(digits.empty())
		return result;
	
	LetterMap letters = {
		{'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
		{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', ""}
	};
	
	queue<string> q;
	q.push("");
	for(int i = 0; i < digits.size(); i++) {
		while(q.front().size() == i) {
			string partial = q.front();
			q.pop();
			for(char& c: letters[digits[i]])
				q.push(partial + c);
		}
	}
	
	while(!q.empty()) {
		result.push_back(q.front());
		q.pop();
	}
	
	return result;
}