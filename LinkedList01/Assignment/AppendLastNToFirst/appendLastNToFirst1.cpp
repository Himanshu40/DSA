// Coding Ninja Solution
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

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the size of the singly LL
*/

Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0 || head == NULL) {
        return head;
    }

    Node *fast = head;
    Node *slow = head;
    Node *initialHead = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    Node *temp = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
    head = temp;
    
    return head;
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
