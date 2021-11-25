// My solution
#include <iostream>

using namespace std;

class Node {
    public:
	    int data;
	    Node *next;
	        
        Node(int data) {
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

Node *skipMdeleteN(Node *head, int M, int N) {
    if (!head || !head->next) {
        return head;
    }
    
    if (!N) {
        return head;
    }
    
    Node *temp1 {head};
    Node *temp2 {nullptr};
    
    while (true) {
        for (int i {1}; i < M && temp1->next; ++i) {
            temp1 = temp1->next;                
        }
        
        if (!M) {
            temp2 = temp1;
        }
        else {
        	temp2 = temp1->next;
        }
        
        for (int j {1}; j <= N && temp2; ++j) {
            Node *deleteNode {temp2};
            temp2 = temp2->next;
                
            delete deleteNode;
        }
        
        if (!temp2) {
            if (!M) {
                return nullptr;
            }
            temp1->next = temp2;
            return head;
        }
        
        temp1->next = temp2;
        temp1 = temp2;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
