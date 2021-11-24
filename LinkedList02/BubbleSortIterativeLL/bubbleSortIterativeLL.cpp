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

void print(Node *head) {
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
        node = node->next;
        ++count;
    }
    
    return count;
}

Node *bubbleSort(Node *head)
{
    if (!head || !head->next) {
        return head;
    }
    
    bool check;
    int size {length(head)};
    
    Node *temp;
    Node *prev;
    
    for (int i {0}; i < size - 1; ++i) {
        check = false;
        prev = nullptr;
        temp = head;
        
        for (int j {0}; j < size - i - 1; ++j) {
            if (temp->data > temp->next->data) {
                if (!prev) {
                    Node *currNext {temp->next};
                    
                    temp->next = currNext->next;
                    currNext->next = temp;
                    prev = currNext;
                    head = prev;
                }
                else {
                    Node *currNext {temp->next};
                    
                    prev->next = currNext;
                    temp->next = currNext->next;
                    currNext->next = temp;
                    prev = currNext;
                }
                
                check = true;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        if (!check) {
            return head;
        }
    }
    
    return head;
}

int main() {
	Node *head = takeinput();
    head = bubbleSort(head);
	print(head);

    return 0;
}
