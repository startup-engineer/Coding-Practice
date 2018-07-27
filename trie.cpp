#include <iostream>
#include <stack>

using namespace std;

class TrieNode {
public:
	static const int ALPHABET_SIZE = 26;
	string word;
	bool is_word;
	TrieNode* children[ALPHABET_SIZE];

	TrieNode() {
		word = "";
		is_word = false;
		for(TrieNode*& t : children)
			t = NULL;
	}

	TrieNode(string word) {
		this->word = word;
		this->is_word = false;
		for(TrieNode*& t : children)
			t = NULL;
	}
};

class Trie {
public:
	TrieNode root;

	Trie() : root()
	{
		
	}

	void add(string word) {
		if(word.empty())
			return;

		TrieNode* t = &root;
		for(char c : word)
		{
			if(t->children[c - 'a'] != NULL){
				t = t->children[c - 'a'];
			} else {
				t->children[c - 'a'] = new TrieNode(t->word + c);
				t = t->children[c - 'a'];
			}
		}

		t->is_word = true;
	}

	void find(string word) {
		// TODO
	}

	void print_words() {
		// print words in an in-order traversal (DFS) manner

		stack<TrieNode*> s;
		s.push(&root);
		while(!s.empty())
		{
			TrieNode* t = s.top();
			s.pop();

			if(t->is_word)
				cout << t->word << endl;

			for(TrieNode* np : t->children) // will print the words in reverse alpha order
				if(np != NULL)
					s.push(np);
		}
	}
};

int main()
{
	Trie t;
	t.add("hello");
	t.add("peter");
	t.add("piper");
	t.add("picked");
	t.add("a");
	t.add("peck");
	t.add("of");
	t.add("pickled");
	t.add("peppers");
	t.add("pranoti");

	t.print_words();
}