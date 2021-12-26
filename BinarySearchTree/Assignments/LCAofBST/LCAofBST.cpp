#include <iostream>
#include <queue>

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

BinaryTreeNode<int> *getLCAHelper(BinaryTreeNode<int> *root, int a, int b) {
    if (root == nullptr || root->data == a || root->data == b) {
        return root;
    }

    if (root->data < a && root->data < b) {
        return getLCAHelper(root->right, a, b);
    }
    else if (root->data > a && root->data > b) {
        return getLCAHelper(root->left, a, b);
    }

    BinaryTreeNode<int> *lLCA {getLCAHelper(root->left, a, b)};
    BinaryTreeNode<int> *rLCA {getLCAHelper(root->right, a, b)};

    if (lLCA != nullptr && rLCA != nullptr) {
        return root;
    }
    else if (lLCA != nullptr) {
        return lLCA;
    }

    return rLCA;
}

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    BinaryTreeNode<int> *node {getLCAHelper(root, val1, val2)};

    return node == nullptr ? -1 : node->data;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}