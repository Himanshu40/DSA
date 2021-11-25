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

    where N is the size of singly LL
*/

Node *removeDuplicates(Node *head)
{   
    if (!head) {
        return head;
    }
    
    Node *currHead = head;
    
    while (currHead->next != nullptr) {
        if (currHead->data == currHead->next->data) {
            currHead->next = currHead->next->next;
        }
        else {
            currHead = currHead->next;
        }
    }
    
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}