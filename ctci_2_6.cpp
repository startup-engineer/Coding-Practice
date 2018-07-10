#include <iostream>

using namespace std;

class Stack {
public:
	int size;
	char* array;
	int top_ptr;

	Stack() {
		array = new char[32];
		top_ptr = 0;
		size = 32;
	}

	void push(char c) {
		if(top_ptr < size) {
			top_ptr++;
			array[top_ptr] = c;
		}
	}

	char pop() {
		if(top_ptr > 0)
			return array[top_ptr--];
		else 
			return 0;
	}

	void print() {
		for(int i = top_ptr; i >= 0; i--)
			cout << array[i] << endl;
	}
};

class Node {
public:
	Node* next;
	char data;

	Node(char data) {
		this->data = data;
		this->next = NULL;
	}

	void append(char data) {
		Node* current = this;
		while(current->next != NULL) 
			current = current->next;

		Node* node = new Node(data);
		current->next = node;
	}
};

bool is_palindrome(Node* root)
{
	Stack s;

	Node *curr = root;
	while(curr != NULL) {
		s.push(curr->data);
		curr = curr->next;
	}

	s.print();

	curr = root;
	while(curr != NULL) {
		if(curr->data != s.pop())
			return false;
		curr = curr->next;
	}

	return true;
}

int main() {
	Node root('A');
	root.append('b');
	root.append('c');
	root.append('c');
	root.append('b');
	root.append('A');

	cout << "is palindrome: " << is_palindrome(&root) << endl;
}