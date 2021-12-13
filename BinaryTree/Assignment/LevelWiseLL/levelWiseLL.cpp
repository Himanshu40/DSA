#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if (!root) {
    	vector<Node<int> *> output;
        output.push_back(nullptr);
        
    	return output;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(nullptr);

    Node<int> *head {nullptr};
    Node<int> *tail {nullptr};

    vector<Node<int> *> output;

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        if (front) {
            Node<int> *node {new Node<int>(front->data)};

            if (!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = tail->next;
            }

            if (front->left) {
                pendingNodes.push(front->left);
            }

            if (front->right) {
                pendingNodes.push(front->right);
            }
        }
        else {
            output.push_back(head);
            head = tail = nullptr;

            if (pendingNodes.empty() == true) {
                break;
            }
            else {
                pendingNodes.push(nullptr);
            }
        }
    }

    return output;
}

int main() {
    BinaryTreeNode<int> *root {takeInput()};
    vector<Node<int> *> ans {constructLinkedListForEachLevel(root)};

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }

    return 0;
}
