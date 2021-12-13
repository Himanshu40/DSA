#include <iostream>
#include <queue>
#include <stack>

using namespace std;

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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }

    stack<BinaryTreeNode<int> *> pendingNodes1;
    stack<BinaryTreeNode<int> *> pendingNodes2;
    int level {0};

    pendingNodes1.push(root);

    while (pendingNodes1.empty() != true || pendingNodes2.empty() != true) {
        if (level % 2 == 0) {
            BinaryTreeNode<int> *top {pendingNodes1.top()};
            pendingNodes1.pop();

            if (top->left != nullptr) {
                pendingNodes2.push(top->left);
            }

            if (top->right != nullptr) {
                pendingNodes2.push(top->right);
            }

            cout << top->data << " ";
            
            if (pendingNodes1.empty() == true) {
                cout << endl;
                level++;
            }
        }
        else {
            BinaryTreeNode<int> *top {pendingNodes2.top()};
            pendingNodes2.pop();

            if (top->right != nullptr) {
                pendingNodes2.push(top->right);
            }
            
            if (top->left != nullptr) {
                pendingNodes1.push(top->left);
            }

            cout << top->data << " ";
            
            if (pendingNodes2.empty() == true) {
                cout << endl;
                level++;
            }
        }
        
        if (pendingNodes1.empty() == true && pendingNodes2.empty() == true) {
            break;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);

    return 0;
}
