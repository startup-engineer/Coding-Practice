#include <iostream>
#include <map>
#include <set>

using namespace std;

// code to remove duplicates from an unsorted linked list

// questions: singly linked or doubly linked?

class Node
{
private:
	Node* next;
	Node* prev;
	int data;

public:
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}

	int getData() {
		return data;
	}

	void setData(int data) {
		this->data = data;
	}

	Node* getNext(){
		return next;
	}

	Node* getPrev(){
		return prev;
	}

	void setNext(Node * next){
		this->next = next;
	}

	void setPrev(Node * prev){
		this->prev = prev;
	}

	void append(int data) {
		if(next == NULL) {
			next = new Node(data);
			next->setPrev(this);
		} else {
			next->append(data);
		}
	}

	void remove() {
		if(this->prev != NULL)
			this->prev->next = this->next;

		if(this->next != NULL)
			this->next->prev = this->prev;

		delete(this);
	}

	void print() {
		if(next != NULL) {
			cout << "(" << data << ")->";
			next->print();
		} else
			cout << "(" << data << ")" << endl;
	}
};

void remove_duplicates(Node * root){
	set<int> seen_values;

	Node* current = root;
	while(current != NULL)
	{
		set<int>::iterator seen_val = seen_values.find(current->getData());
		if(seen_val == seen_values.end()) {
			seen_values.insert(current->getData());
			current = current->getNext();
		} else {
			Node* temp = current->getNext();
			current->remove();
			current = temp;
		}
	}
}

Node* kth_to_last(Node* root, int k) {
	int i = 1;
	Node* current = root;
	Node* k_ptr = NULL;

	while(current != NULL)
	{
		if(i == k)
			k_ptr = root;

		if(current->getNext() != NULL)
			current = current->getNext();
		else
			return k_ptr;

		if(k_ptr != NULL)
			k_ptr = k_ptr->getNext();

		i++;
	}
}

int main() {
	Node root(101);
	root.append(102);
	root.append(103);
	root.append(104);
	root.append(105);
	root.append(106);
	root.append(107);
	root.append(108);

	root.print();

	remove_duplicates(&root);
	cout << kth_to_last(&root, 4)->getData() << endl;

	root.print();
}