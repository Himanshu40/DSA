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

class Pair {
    public:
    	Node *head;
    	Node *tail;
};

Pair reverseLL(Node *head) {
    if (!head || !head->next) {
        Pair ans;

        ans.head = head;
        ans.tail = head;

        return ans;
    }

    Pair smallAns = reverseLL(head->next);

    smallAns.tail->next = head;
    head->next = nullptr;

    smallAns.tail = smallAns.tail->next;

    return smallAns;
}

Node *kReverse(Node *head, int k) {
    if (!head || !head->next || !k) {
        return head;
    }
    
    int count {1};
    
    Node *head1 {head};
    Node *tail1 {head};
    
    while (count < k && tail1->next) {
        tail1 = tail1->next;
        ++count; 
    }
    
    Node *head2 {tail1->next};
    tail1->next = nullptr;
    
    Pair reverse = reverseLL(head1);
    Node *head3 = kReverse(head2, k);
    reverse.tail->next = head3;
    
    return reverse.head;
}

int main() {
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}
