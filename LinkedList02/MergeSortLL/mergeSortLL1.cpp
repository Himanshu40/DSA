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

Node *midPoint(Node *head)
{
    // Write your code here
    if (!head) {
        return head;
    }
    
    Node *fast = head;
    Node *slow = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }
    
    Node *finalHead {nullptr};
    Node *finalTail {nullptr};
    
    if (head1->data <= head2->data) {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
    }
    else {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            finalTail->next = head1;
            finalTail = head1;
            head1 = head1->next;
        }
        else {
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
    }
    
    if (!head1) {
        finalTail->next = head2;        
    }
    
    if (!head2) {
        finalTail->next = head1;        
    }
    
    return finalHead;
}

/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    where N is the size of the singly LL
*/

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *mid = midPoint(head);

    Node *half1 = head;
    Node *half2 = mid->next;
    mid->next = nullptr;
    
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);
    
    Node *finalHead = mergeTwoSortedLinkedLists(half1, half2);
    
    return finalHead;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
