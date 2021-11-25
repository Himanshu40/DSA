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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if (!head || !head->next) {
        return head;
    }
    
    Node *oddHead  {nullptr};
    Node *oddTail  {nullptr};
    Node *evenHead {nullptr};
    Node *evenTail {nullptr};
    
    while (head) {
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

    if (evenTail && oddTail) {
        evenTail->next = nullptr;
        oddTail->next = evenHead;

        return oddHead;
    }
    else if (oddTail) {
        oddTail->next = nullptr;

        return oddHead;
    }

    evenTail->next = nullptr;
    return evenHead;
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