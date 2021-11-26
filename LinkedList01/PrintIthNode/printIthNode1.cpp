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
    Time Complexity: O(min(i, n))
    Space Complexity: O(1)

    where i is the position of the element to be printed
    and n is the size of the singly LL
*/

void printIthNode(Node *head, int i)
{
    int count {0};
    Node *temp = head;
    
    while (temp != nullptr && count < i) {
        ++count;
        temp = temp->next;
    }

    if (temp != nullptr) {
        cout << temp->data;
    }
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}

	return 0;
}