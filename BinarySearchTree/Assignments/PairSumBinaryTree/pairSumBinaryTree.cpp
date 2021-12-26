#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

void preOrder(BinaryTreeNode<int> *root, vector<int> &elements) {
    if (!root) {
        return;
    }

    elements.push_back(root->data);

    preOrder(root->left, elements);
    preOrder(root->right, elements);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> elements;

    preOrder(root, elements);

    sort(elements.begin(), elements.end());

    int i = 0;
    int j = elements.size() - 1;

    while (i < j) {
        if (elements[i] + elements[j] < sum) {
            ++i;
        }
        else if (elements[i] + elements[j] > sum) {
            --j;
        }
        else {
            cout << elements[i] << " " << elements[j];

            ++i;
            --j;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;

    return 0;
}
