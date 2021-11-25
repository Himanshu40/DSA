#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

class Pair {
    public:
        Node *head;
        Node *tail;
};

Pair reverseLL2(Node *head) {
    if (!head || !head->next) {
        Pair ans;

        ans.head = head;
        ans.tail = head;

        return ans;
    }

    Pair smallAns = reverseLL2(head->next);

    smallAns.tail->next = head;
    smallAns.tail = head;
    head->next = nullptr;

    return smallAns;
}

Node *reverseLL1(Node *head) {
    return reverseLL2(head).head;
}

Node *takeInput() {
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

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
    Node *head = takeInput();
    head = reverseLL1(head);

    print(head);

    return 0;
}
