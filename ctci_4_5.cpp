#include <stack>
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int traverse(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    s.push(curr);
    curr = curr->left;
    while(!s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << endl;
        curr = curr->right;
    }
}

int main(){
    Node a(10);
    Node b(5);
    Node c(0);
    Node d(3);
    Node e(2);
    Node f(1);
    Node g(4);

    a.left = &b;
    b.left = &c;
    c.right = &d;
    d.left = &e;
    d.right = &g;
    e.left = &f;

    traverse(&a);
}