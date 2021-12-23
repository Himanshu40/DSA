#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<Node<int> *, Node<int> *> constructLinkedListHelper(BinaryTreeNode<int> *root) {
    if (!root) {
        pair<Node<int> *, Node<int> *> answer(nullptr, nullptr);

        return answer; 
    }

    Node<int> *node {new Node<int>(root->data)};

    pair<Node<int> *, Node<int> *> rootLeft  {constructLinkedListHelper(root->left)};
    pair<Node<int> *, Node<int> *> rootRight {constructLinkedListHelper(root->right)};

    pair<Node<int> *, Node<int> *> answer;

    if (!rootLeft.first && !rootRight.first) {
        answer.first = answer.second = node;
    }
    else if (!rootLeft.first) {
        answer.first = node;
        node->next = rootRight.first;
        answer.second = rootRight.second;
    }
    else if (!rootRight.first) {
        answer.first = rootLeft.first;
        rootLeft.second->next = node;
        answer.second = node;
    }
    else {
        answer.first = rootLeft.first;
        rootLeft.second->next = node;
        node->next = rootRight.first;
        answer.second = rootRight.second;
    }


    return answer;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    pair<Node<int> *, Node<int> *> answer {constructLinkedListHelper(root)};
    
    return answer.first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}