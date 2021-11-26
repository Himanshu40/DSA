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

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the length of the singly LL
*/

Node* insertNode(Node *head, int i, int data) {
    if (head == nullptr) {
        if (i == 0) {
            Node *newNode = new Node(data);

            return newNode;
        }

        return head;
    }
    
    Node *newNode = new Node(data);
    
    if (i == 0) {
        newNode->next = head;
        head = newNode;
        
        return head;
    }
    
    head->next = insertNode(head->next, i - 1, data);
    return head;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }

    return 0;
}
