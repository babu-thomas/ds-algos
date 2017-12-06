// Given a stack of N elements, interleave the first half of the stack with the second half reversed
// using one other queue. 
// For example,
// Input stack - [1, 2, 3, 4, 5]
// Output stack - [1, 5, 2, 4, 3]

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void stack2queue(stack<int>& s, queue<int>& q)
{
	if(s.size() == 1) {
		q.push(s.top());
	}
	else {
		int element = s.top();
		s.pop();
		stack2queue(s, q);
		s.push(element);
		q.push(element);
	}
}

stack<int> interleave(stack<int> s)
{
	queue<int> q;
	stack2queue(s, q);
	stack<int> result;
	int len = s.size();
	bool from_stack = false;
	for(int i = 0; i < len; i++) {
		if(from_stack) {
			result.push(s.top());
			s.pop();
		}
		else {
			result.push(q.front());
			q.pop();
		}
		from_stack = !from_stack;
	}
	return result;
}

int main()
{
	stack<int> s;
	for(int i = 1; i <= 5; i++)
		s.push(i);
		
	stack<int> result = interleave(s);
	while(s.size() != 0) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
	
	while(result.size() != 0) {
		cout << result.top() << " ";
		result.pop();
	}
	cout << "\n";
	return 0;
}