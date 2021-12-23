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

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

BinaryTreeNode<int>* constructTreeHelper(int *arr, int start, int end) {
    if (start >= end) {
        BinaryTreeNode<int> *root {new BinaryTreeNode<int>(arr[end])};

        return root;
    }

    int pivot {arr[start + (end - start)/2]};
    int position {start + (end - start) / 2};

    BinaryTreeNode<int> *root {new BinaryTreeNode<int>(pivot)};
    BinaryTreeNode<int> *left {constructTreeHelper(arr, start, position)};
    BinaryTreeNode<int> *right {constructTreeHelper(arr, position + 1, end)};

    root->left = left;
    root->right = right;

    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return constructTreeHelper(input, 0, n - 1);
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;

    return 0;
}
