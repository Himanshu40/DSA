// My solution
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

int length(Node *node) {
    int count {0};
    
    while (node != nullptr) {
        ++count;
        node = node->next;
    }
    
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
	int totalSize = length(head);
    
    if (n < totalSize) {
        int range = totalSize - n;
        Node *temp = head;
        
        for (int i {0}; (i < range - 1) && (temp != nullptr); ++i) {
            temp = temp->next;
        }
        
        Node *prev = temp;
        
        for (int i {0}; i < n && (temp != nullptr); ++i) {
            temp = temp->next;
        }
        
        temp->next = head;
        head = prev->next;
        prev->next = nullptr;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
