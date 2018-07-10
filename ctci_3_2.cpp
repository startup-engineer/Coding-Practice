#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	T min;
	Node<T>* prev;

	Node(T data) {
		this->data = data;
		this->min = 0;
	}
};

template <typename T>
class Stack
{
private:
	Node<T>* top;
public:
	Stack() {
		top = NULL;
	}

	T min() {
		return top->min;
	}

	void push(T data) {
		Node<T>* n = new Node<T>(data);

		if(top != NULL)
			if(n->data < top->min)
				n->min = n->data;
			else
				n->min = top->min;
		else
			n->min = n->data;

		n->prev = top;
		top = n;
	}

	T pop() {
		T data = top->data;
		Node<T>* prev = top->prev;
		delete(top);
		top = prev;
		return data;
	}

	T peek() {
		if(top != NULL)
			return top->data;
	}

	bool isEmpty() {
		if(top == NULL)
			return true;
		else
			return false;
	}
};

int main()
{
	Stack<int> s;

	cout << "Peek : Min" << endl;
	s.push(1);
	cout << s.peek() << "    : " << s.min() << endl;
	s.push(2);
	cout << s.peek() << "    : " << s.min() << endl;
	s.push(3);
	cout << s.peek() << "    : " << s.min() << endl;
	s.push(0);
	cout << s.peek() << "    : " << s.min() << endl;
	s.push(1);
	cout << s.peek() << "    : " << s.min() << endl;
	s.pop();
	cout << s.peek() << "    : " << s.min() << endl;
	s.pop();
	cout << s.peek() << "    : " << s.min() << endl;
	s.pop();
	cout << s.peek() << "    : " << s.min() << endl;
	s.pop();
	cout << s.peek() << "    : " << s.min() << endl;

}