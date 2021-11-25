// My solution
#include <iostream>
#include <stdlib.h>

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

Node *takeinput() {
	int data;
	cin >> data;

	Node *head = NULL, *tail = NULL;
	
    while (data != -1) {
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
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
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int length(Node *node) {
    int count {0};
    
    while (node) {
        ++count;
        node = node->next;
    }
    
    return count;
}

Node *swapNodes(Node *head, int i, int j) {
    if (!head || !head->next) {
        return head;
    }

    if (i == j) {
        return head;
    }
    
    int totalSize = length(head);
    
    if (i > totalSize || j > totalSize) {
        return head;
    }
    
    Node *temp {head->next};
    Node *tempPrev {head};
    Node *prev1 {nullptr};
    Node *curr1 {nullptr};
    Node *prev2 {nullptr};
    Node *curr2 {nullptr};
    
    int count {1};
    
    if (i > j) {
        int temp {i};
        
        i = j;
        j = temp;
    }
    
    while (temp) {
        if (count == i) {
            curr1 = temp;
            prev1 = tempPrev;
        }
        
        if (count == j) {
            curr2 = temp;
            prev2 = tempPrev;
            break;
        }
        
        tempPrev = tempPrev->next;
        temp = temp->next;
        ++count;
    }

    
	if (!i) {
        if (j == 1) {
            prev2->next = curr2->next;
            curr2->next = prev2;
            head = curr2;
        
            return head;
        }
        
        curr1 = head;
        Node *curr1Next {head->next};
        curr1->next = curr2->next;
        prev2->next = curr1;
        curr2->next = curr1Next;
        head = curr2;
    }
    else if (j - i == 1) {
        prev1->next = curr2;
        prev2->next = curr2->next;
        curr2->next = prev2;
    }
    else {
        Node*extra {curr1->next};
            
        prev2->next = curr1;
        curr1->next = curr2->next;
        prev1->next = curr2;
        curr2->next = extra;         
    }
    
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int i, j;

		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}

	return 0;
}
