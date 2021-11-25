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
    Time Complexity: O(N + M)
    Space Complexity: O(1)

    where N and M are the sizes of the singly linked list
*/

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL) {
        return head2;
    }
    
    if (head2 == NULL) {
        return head1;
    }
    
    Node *finalHead {nullptr};
    Node *finalTail {nullptr};
    
    if (head1->data <= head2->data) {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
    }
    else {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            finalTail->next = head1;
            finalTail = head1;
            head1 = head1->next;
        }
        else {
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
    }
    
    if (!head1) {
        finalTail->next = head2;        
    }
    
    if (!head2) {
        finalTail->next = head1;        
    }
    
    return finalHead;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
