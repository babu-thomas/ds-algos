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
void delete_list(Node **head_ref);
int pop(Node **head_ref);
void insert_at(int index, int data, Node **head_ref);
void move_node(Node **src_ref, Node **dest_ref);


// Adds a node to the beginning of the linked list
void push(Node **head_ref, int data)
{
	Node* new_node = new Node{data, *head_ref};
	(*head_ref) = new_node;
}

// Makes a linked list from the elements of the array. The elements are added in the same order as
// in the array.
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

// In this version, separate case for first element is avoided by using a reference pointer that
// points to the next pointer of the last node
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

void delete_list(Node **head_ref)
{
	Node *next = nullptr;
	for(Node *i = *head_ref; i != nullptr; ) {
		next = i->next;
		free(i);
		i = next;
	}
	(*head_ref) = nullptr;
}

int pop(Node **head_ref)
{
	assert((*head_ref) != nullptr);
	int data = (*head_ref)->data;
	(*head_ref) = (*head_ref)->next;
	
	return data;
}

// Inserts a new node at given index with given data. Pass one past end index to insert at end.
void insert_at(int index, int data, Node **head_ref)
{
	assert(index <= length(*head_ref));
	Node **last_ptr = head_ref;
	Node *new_node = new Node{data, nullptr};
	int i = 0;
	for(Node *node = *head_ref; node != nullptr; node = node->next) {
		if(i == index) {
			new_node->next = *last_ptr;
			(*last_ptr) = new_node;
			return;
		}
		last_ptr = &((*last_ptr)->next);
		++i;
	}
	(*last_ptr) = new_node;
}

// Removes the front node of the first list and inserts it into front of the second list
void move_node(Node **src_ref, Node **dest_ref)
{
	assert(*src_ref != nullptr);
	Node *src_next = (*src_ref)->next;
	(*src_ref)->next = *dest_ref;
	(*dest_ref) = *src_ref;
	(*src_ref) = src_next;
}

int main()
{
	int data[] = {1, 2, 3, 4, 5};
	int len = sizeof(data)/sizeof(int);
	Node* head1 = from_array1(data, len);
	print(head1);
	Node* head2 = from_array2(data, len);
	print(head2);
	for(int i = 0; i < 4; i++)
		move_node(&head1, &head2);
	print(head1);
	print(head2);
	Node* head3 = from_array3(data, len);
	pop(&head3);
	pop(&head3);
	push(&head3, 6);
	print(head3);
	insert_at(2, 7, &head3);
	insert_at(0, 8, &head3);
	insert_at(6, 9, &head3);
	print(head3);
		
	cout << length(head1) << "\n";
	cout << count_of(3, head1) << "\n";
	cout << get_nth(4, head2) << "\n";
	delete_list(&head2);
	delete_list(&head3);
	return 0;
}