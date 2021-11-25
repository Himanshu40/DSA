// My Solution
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

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    
    if (!head) {
        return head;
    }
    
    if (temp->next != nullptr) {
        temp = temp->next;
    }
    else {
        return head;
    }
    
    Node *prev = head;
    
    while (temp != nullptr) {
        if (temp->data == prev->data) {
            if (temp->next != nullptr) {
                prev->next = temp->next;
                delete temp;
                
                temp = prev->next;
            }
            else {
            	prev->next = nullptr;
            	delete temp;
                
                return head;
            }
        }
        else {
            temp = temp->next;
        	prev = prev->next;
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