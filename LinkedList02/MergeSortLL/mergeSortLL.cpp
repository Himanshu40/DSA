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

int getLength(Node *node) {
    int count {0};
    
    while (node) {
        ++count;
        node = node->next;
    }
    
    return count;
}

Node *midPoint(Node *head)
{
    // Write your code here
    if (!head) {
        return head;
    }
    
    if (!head->next) {
        return head;
    }
    
    Node *fast = head->next;
    Node *slow = head;
    
    while (fast) {
        if (!fast->next) {
            return slow;
        }
        slow = slow->next;
        
        if (!fast->next->next) {
            return slow;
        }
        fast = fast->next->next;
    }
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
	if (head1 == nullptr) {
        if (head2 == nullptr) {
            return head1;
        }
        else {
            return head2;
        }
    }
    else {
        if (head2 == nullptr) {
            return head1;
        }
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

Node *mergeSort(Node *head)
{
	//Write your code here
    int totalSize = getLength(head);
    
    if (totalSize == 0 || totalSize == 1) {
        return head;
    }
    
    Node *part1Head = head;
    Node *mid = midPoint(part1Head);
    Node *part2Head = mid->next;
    mid->next = nullptr;
    part1Head = mergeSort(part1Head);
    part2Head = mergeSort(part2Head);
    head = mergeTwoSortedLinkedLists(part1Head, part2Head);
    
    return head;
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
