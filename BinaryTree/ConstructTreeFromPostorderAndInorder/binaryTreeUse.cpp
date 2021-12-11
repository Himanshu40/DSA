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

BinaryTreeNode<int>* buildTreeHelper(int *postorder, int postorderStart, int postorderEnd, int *inorder, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootData {postorder[postorderEnd]};

    int rootIndex {-1};
    for (int i {inorderStart}; i <= inorderEnd; ++i){
        if (inorder[i] == postorder[postorderEnd]) {
            rootIndex = i;
            break;
        }
    }

    int lInorderStart   {inorderStart};
    int lInorderEnd     {rootIndex - 1};
    int lPostorderStart {postorderStart};
    int lPostorderEnd   {lInorderEnd - lInorderStart + lPostorderStart};

    int rInorderStart   {rootIndex + 1};
    int rInorderEnd     {inorderEnd};
    int rPostorderStart {lPostorderEnd + 1};
    int rPostorderEnd   {postorderEnd - 1};
    
    BinaryTreeNode<int> *root {new BinaryTreeNode<int>(rootData)};

    root->left = buildTreeHelper(postorder, lPostorderStart, lPostorderEnd, inorder, lInorderStart, lInorderEnd);
    root->right = buildTreeHelper(postorder, rPostorderStart, rPostorderEnd, inorder, rInorderStart, rInorderEnd);

    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder) {
    return buildTreeHelper(postorder, 0, postLength - 1, inorder, 0, postLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in);
    printLevelATNewLine(root);

    return 0;
}
