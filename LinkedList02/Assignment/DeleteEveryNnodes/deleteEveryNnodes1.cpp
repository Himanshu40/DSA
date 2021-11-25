// Coding Ninja solution
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

/*
	Time Complexity: O(N)
	Space Complexity: O(1)

	where N is the size of the singly linked list
*/

Node *skipMdeleteN(Node *head, int M, int N) {
    if (M == 0 || head == NULL) {
        return NULL;
    }

    if (!N) {
        return head;
    }

    Node *currentNode = head;
    // temp will keep a copy of currentNode as we modify the list
    Node *temp = NULL;

    while (currentNode != NULL) {
        int take = 0;
        int skip = 0;

        while (currentNode != NULL && take < M) {
            if (temp == NULL) {
                temp = currentNode;
            }
            else {
                temp->next = currentNode;
                temp = currentNode;
            }
            
            currentNode = currentNode->next;
            take++;
        }

        while (currentNode != NULL && skip < N) {
            Node *newNode = currentNode;
            delete currentNode;

            currentNode = currentNode->next;
            skip++;
        }
    }

    if (temp != NULL) {
        temp->next = NULL;
    }

    return head;
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
