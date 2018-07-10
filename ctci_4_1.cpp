#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	bool visited;
	vector<Node<T> > adj;

	Node(T data){
		this->data = data;
		this->visited = false;
	}

	void addAdj(Node<T>& n){
		adj.push_back(n);
	}
};

void BFS(Node root) {

}

void DFS(Node root) {

}

int main() {
	Node<int> a(1);
	Node<int> b(2);
	Node<int> c(3);
	Node<int> d(4);
	Node<int> e(5);

	a.addAdj(b);
	b.addAdj(c);
	b.addAdj(d);
	b.addAdj(e);

	cout << a.data << endl;
}