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

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the size of the singly LL
*/

bool isPalindrome(Node *head)
{
    if (head == nullptr || !head->next) {
        return true;
    }

    // Find center of list
    Node *fast = head;
    Node *slow = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    Node *secondHead = slow->next;
    slow->next = nullptr;
    secondHead = reverse(secondHead);

    // Compare the two sublists
    Node *firstSubList = head;
    Node *secondSubList = secondHead;
    bool ans = true;

    while (secondSubList) {
        if (firstSubList->data != secondSubList->data) {
            ans = false;
            break;
        }
        
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }

    // Rejoin the two sublists
    firstSubList = head;
    secondSubList = reverse(secondHead);
    
    while (firstSubList->next != NULL) {
        firstSubList = firstSubList->next;
    }

    firstSubList->next = secondSubList;
    
    return ans;
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