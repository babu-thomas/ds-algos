// A XOR linked list is a more memory efficient doubly linked list. Instead of each node holding
// next and prev fields, it holds a field named both, which is a XOR of the next node and the
// previous node. Implement a XOR linked list.

#include <iostream>
#include <cstdint>
using namespace std;

struct Node {
	int data;
	Node *ptr;
};

void push(Node **head_ref, int data);
void append(Node **head_ref, int data);
void print(Node *head);
Node* xor_ptr(Node* a, Node* b);

int main()
{
	Node *head = nullptr;
	append(&head, 1);
	append(&head, 2);
	push(&head, 3);
	append(&head, 4);
	print(head);
	return 0;
}

void print(Node *head)
{
	Node *prev = nullptr;
	Node *next = nullptr;
	Node *current = head;
	while(current != nullptr) {
		cout << current->data << " ";
		next = xor_ptr(prev, current->ptr);
		prev = current;
		current = next;
	}
	cout << "\n";
}

// Add a node to beginning of linked list
void push(Node **head_ref, int data)
{
	Node *new_node = new Node{data, *head_ref};
	Node *prev = new_node;
	Node *next = nullptr;
	// If list is not empty
	if(*head_ref != nullptr) {
		next = (*head_ref)->ptr;
		(*head_ref)->ptr = xor_ptr(prev, next);
	}
	*head_ref = new_node;
}

// Add a node to end of linked list
void append(Node **head_ref, int data)
{
	// If list is empty
	if((*head_ref) == nullptr) {
		push(head_ref, data);
		return;
	}
	
	//Find last node
	Node *prev = nullptr;
	Node *next = nullptr;
	Node *current = *head_ref;
	while(current != nullptr) {
		next = xor_ptr(prev, current->ptr);
		prev = current;
		current = next;
	}
	push(&prev, data);
}

// XORs 2 pointers in a safe way by converting them to uintptr_t, XORing and then converting back
Node* xor_ptr(Node* a, Node* b)
{
	return (Node*)((uintptr_t) a ^ (uintptr_t) b);
}