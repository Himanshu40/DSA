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

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the size of the singly linked list
*/

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if (head == NULL) {
        return head;
    }
    
    Node *oddHead  {nullptr};
    Node *oddTail  {nullptr};
    Node *evenHead {nullptr};
    Node *evenTail {nullptr};
    
    while (head != NULL) {
        if (head->data % 2) {
            if (oddHead) {
                oddTail->next = head;
                oddTail = head;
            }
            else {
                oddHead = oddTail = head;
            }
        }
        else {
            if (evenHead) {
                evenTail->next = head;
                evenTail = head;
            }
            else {
                evenHead = evenTail = head;
            }
        }
        
        head = head->next;
    }

    if (oddHead == NULL) {
        return evenHead;
    }
    else {
        oddTail->next = evenHead;
    }

    if (evenHead != NULL) {
        evenTail->next = NULL;
    }

    return oddHead;
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}