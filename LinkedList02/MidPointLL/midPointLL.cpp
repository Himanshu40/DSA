#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *midPoint(Node *head)
{
    // Write your code here
    if (!head) {
        return head;
    }
    
    if (!head->next) {
        return head;
    }
    
    Node *fast = head->next;
    Node *slow = head;
    
    while (fast) {
        if (!fast->next) {
            return slow;
        }
        slow = slow->next;
        
        if (!fast->next->next) {
            return slow;
        }
        fast = fast->next->next;
    }
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}