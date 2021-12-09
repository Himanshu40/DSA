#include <iostream>
#include <queue>
#include "binaryTreeNode.h"

using namespace std;

BinaryTreeNode<int> *takeInputLevelWise() {
    int rootData;
    
    std::cout << "Enter root data: ";
    std::cin >> rootData;

    if (rootData == -1) {
        return nullptr;
    }

    BinaryTreeNode<int> *root {new BinaryTreeNode<int>(rootData)};
    std::queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        std::cout << "Enter left child of " << front->data << ": ";

        int leftChild;
        std::cin >> leftChild;

        if (leftChild != -1) {
            BinaryTreeNode<int> *child {new BinaryTreeNode<int>(leftChild)};
            front->left = child;
            pendingNodes.push(child);
        }

        std::cout << "Enter right child of " << front->data << ": ";

        int rightChild;
        std::cin >> rightChild;

        if (rightChild != -1) {
            BinaryTreeNode<int> *child {new BinaryTreeNode<int>(rightChild)};
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int preorderStart, int preorderEnd, int *inorder, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootIndex {-1};

    for (int i {inorderStart}; i <= inorderEnd; ++i){
        if (inorder[i] == preorder[preorderStart]) {
            rootIndex = i;
            break;
        }
    }
    
    int lInorderStart  {inorderStart};
    int lInorderEnd    {rootIndex - 1};
    int lPreorderStart {preorderStart + 1};
    int lPreorderEnd   {lInorderEnd - lInorderStart + lPreorderStart};

    int rInorderStart  {rootIndex + 1};
    int rInorderEnd    {inorderEnd};
    int rPreorderStart {lPreorderEnd + 1};
    int rPreorderEnd   {preorderEnd};
    
    BinaryTreeNode<int> *root {new BinaryTreeNode<int>(preorder[preorderStart])};

    root->left = buildTreeHelper(preorder, lPreorderStart, lPreorderEnd, inorder, lInorderStart, lInorderEnd);
    root->right = buildTreeHelper(preorder, rPreorderStart, rPreorderEnd, inorder, rInorderStart, rInorderEnd);

    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder) {
    return buildTreeHelper(preorder, 0, preLength - 1, inorder, 0, preLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in);
    printLevelATNewLine(root);

    return 0;
}
