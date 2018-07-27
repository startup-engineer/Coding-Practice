//failed attempt at making a trie

#include <iostream>
#include <vector>
#include <queue>

class Trie
{
public:
	TrieNode root;

	Trie() {
		root = TrieNode();
	}


}

class TrieNode
{
public:
	string word;
	bool is_word;
	vector<TrieNode*> children;

	TrieNode(char c){
		this->character = c;
		this->is_word = false;
	}

	TrieNode(){
		this->character = NULL;
		this->is_word = false;
	}

	void add(string s) 
	{
		for(char c : s)
		{
			TrieNode* t = getChild(c);
			if(t != NULL)
				t->add(s.substr(1));
			else 
			{
				children.push_back(c);
				t = getChild(c);
				t->add(s.substr(1));
			}
		}
	}

	void addChild(char c) {
		children.push_back(TrieNode(c));
	}

	TrieNode* getChild(char c) {
		for(TrieNode t : children)
			if(t.character == c)
				return &t;
		return NULL;
	}

	void print() {
		queue<TrieNode> q;
		for(TrieNode& t : children)
			q.push(t);

		while(!q.empty())
		{
			TrieNode t = q.front();
			q.pop();
			cout << t.character << " ";
		}
	}
};

int main()
{
	TrieNode t;
	t.add("hello");
}