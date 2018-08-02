#include <iostream>

using namespace std;

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(NULL)
    {
    }
};

LinkedListNode* in_place_reverse(LinkedListNode* head);

int main()
{
	LinkedListNode* head = new LinkedListNode(0);

	LinkedListNode* node = head;
	for(int i = 1; i < 100; i++)
	{
		node->next_ = new LinkedListNode(i);
		node = node->next_;
	}

	node = head;
	while(node != NULL)
	{
		cout << node->intValue_ << "->";
		node = node->next_;
	}
	cout << endl << endl;

	head = in_place_reverse(head);

	node = head;
	while(node != NULL)
	{
		cout << node->intValue_ << "->";
		node = node->next_;
	}
	cout << endl;

}

LinkedListNode* in_place_reverse(LinkedListNode* head)
{
	if(head == NULL || head->next_ == NULL)
		return head;

	LinkedListNode* a = head;
	LinkedListNode* b = a->next_;

	a->next_ = NULL;

	LinkedListNode* suffix = b->next_;

	while(suffix != NULL)
	{
		b->next_ = a;

		a = b;
		b = suffix;
		suffix = suffix->next_;
	}

	b->next_ = a;

	return b;
}