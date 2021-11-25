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

int length(Node *node) {
    int count {0};
    
    while (node) {
        ++count;
        node = node->next;
    }
    
    return count;
}

Node *reverse(Node *head) {
    Node *prev {nullptr};
    Node *next {nullptr};
    Node *curr {head};
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
    return head;
}

bool isPalindrome(Node *head)
{
    if (head == nullptr) {
        return true;
    }
    
    if (!head->next) {
        return true;
    }
    
	int totalSize = length(head) / 2;
    
    Node *firstHalf {head};
    for (int i {1}; i < totalSize; ++i) {
        firstHalf = firstHalf->next;
    }
    
    Node *secondHalf = reverse(firstHalf->next);
    firstHalf->next = nullptr;
    firstHalf = head;
    
    while (firstHalf && secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}