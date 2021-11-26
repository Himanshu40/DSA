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


int length(Node *head) {
   
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

/*
    Time Complexity: O(min(I, N))
    Space Complexity: O(1)

    where I is the position of the node to be
    deleted and N is the size of the singly LL
*/

Node* deleteNode(Node *head, int i) {
   if (head == NULL) {
       return head;
   }

   if (i == 0) {
       return head->next;
   }

    Node *curr=head;
    int currpos = 0;

    while (curr != NULL && currpos < i - 1) {
        ++currpos;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        return head;
    }

    curr->next = curr->next->next;

    return head;
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
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}