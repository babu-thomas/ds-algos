#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void push(Node **head_ref, int data);
Node* from_array1(int *array, int len);
Node* from_array2(int *array, int len);
Node* from_array3(int *array, int len);
void print(Node *head);
int length(Node *head);
int count_of(int data, Node *head);
int get_nth(int n, Node *head);

// Adds a node to the beginning of the linked list
void push(Node **head_ref, int data)
{
	Node* new_node = new Node{data, *head_ref};
	(*head_ref) = new_node;
}

// Makes a linked list from the elements of the array. The elements are added in the same order as in the array.
// In this version, insertion of first element is handled separately.
Node* from_array1(int *array, int len)
{
	Node* head = nullptr;
	Node* tail = nullptr;
	
	push(&head, array[0]);
	tail = head;
	
	for(int i = 1; i < len; i++)
	{
		push(&(tail->next), array[i]);
		tail = tail->next;
	}
	
	return head;
}

// In this version, separate case for first element is avoided by using temporary dummy node
Node* from_array2(int *array, int len)
{
	Node dummy;
	dummy.next = nullptr;
	Node* tail = &dummy;
	
	for(int i = 0; i < len; i++)
	{
		push(&(tail->next), array[i]);
		tail = tail->next;
	}
	
	return dummy.next;
}

// In this version, separate case for first element is avoided by using a reference pointer that points to the next pointer of the last node
Node* from_array3(int *array, int len)
{
	Node *head = nullptr;
	Node** last_ptr = &head;
	
	for(int i = 0; i < len; i++)
	{
		push(last_ptr, array[i]);
		last_ptr = &((*last_ptr)->next);
	}
	
	return head;
}

void print(Node *head)
{
	for(Node *i = head; i != nullptr; i = i->next) {
		cout << i->data << " ";
	}
	cout << "\n";
}

int length(Node *head)
{
	int count = 0;
	for(Node *i = head; i != nullptr; i = i->next) {
		++count;
	}
	
	return count;
}

int count_of(int data, Node *head)
{
	int count = 0;
	for(Node *i = head; i != nullptr; i = i->next) {
		if(i->data == data)
			++count;
	}
	
	return count;
}

int get_nth(int n, Node *head)
{
	assert(n < length(head));
	int index = 0;
	for(Node *node = head; node != nullptr; node = node->next, ++index) {
		if(index == n)
			return node->data;
	}
	
	return 0;
}

int main()
{
	int data[] = {1, 2, 3, 4, 5};
	int len = sizeof(data)/sizeof(int);
	Node* head1 = from_array1(data, len);
	print(head1);
	Node* head2 = from_array2(data, len);
	print(head2);
	Node* head3 = from_array3(data, len);
	print(head3);
	
	cout << length(head1) << "\n";
	cout << count_of(3, head1) << "\n";
	cout << get_nth(4, head1) << "\n";
	return 0;
}