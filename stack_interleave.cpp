// Given a stack of N elements, interleave the first half of the stack with the second half reversed
// using one other queue.
// For example,
// Input stack - [1, 2, 3, 4, 5]
// Output stack - [1, 5, 2, 4, 3]

// 1. Solution using recursion to insert stack elements in reverse order into the queue.
//    Time - O(N), space - O(N).
// 2. Solution using only queue and no recursion stack. Time - O(N), space - O(N).

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print_stack(stack<int> s)
{
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

void print_queue(queue<int> q)
{
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";
}

stack<int> alternate_insert(stack<int> s, queue<int> q, int times)
{
	stack<int> result;
	bool from_stack = false;
	for(int i = 0; i < times; i++) {
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

void stack2queue(stack<int>& s, queue<int>& q)
{
	if(s.empty())
		return;
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

stack<int> interleave1(stack<int> s)
{
	queue<int> q;
	stack2queue(s, q);
	int len = s.size();
	bool from_stack = false;
	
	return alternate_insert(s, q, len);
}

stack<int> interleave2(stack<int> s)
{
	queue<int> q;
	int len = s.size();
	int half = len / 2;
	// Initially,
	// S = 5 4 3 2 1
	// Q = Empty
	
	// Step 1
	// S = 3 2 1
	// Q = 5 4
	for(int i = 0; i < half; i++) {
		q.push(s.top());
		s.pop();
	}
	// Step 2
	// S = 4 5 3 2 1
	// Q = Empty
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	// Step 3
	// S = Empty
	// Q = 4 5 3 2 1
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	// Step 4
	// S = 1 2 3 5 4
	// Q = Empty
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	// Step 5
	// S = 5 4
	// Q = 1 2 3
	for(int i = 0; i < len - half; i++) {
		q.push(s.top());
		s.pop();
	}
	
	return alternate_insert(s, q, len);
}

int main()
{
	stack<int> s;
	for(int i = 1; i <= 5; i++)
		s.push(i);
	print_stack(s);
	stack<int> result = interleave1(s);
	print_stack(result);
	result = interleave2(s);
	print_stack(result);
	return 0;
}