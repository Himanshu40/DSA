#include <iostream>
#include <queue>
#include "binaryTreeNode.h"

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    std::cout << "Enter data: ";
    std::cin >> rootData;

    if (rootData == -1) {
        return nullptr;
    }

    BinaryTreeNode<int> *root {new BinaryTreeNode<int>(rootData)};
    BinaryTreeNode<int> *leftChild {takeInput()};
    BinaryTreeNode<int> *rightChild {takeInput()};

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

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

void printTree(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }
    
    std::cout << root->data << ": ";
    if (root->left) {
        std::cout << "L" << root->left->data;
    }

    if (root->right) {
        std::cout << "R" << root->right->data;
    }

    std::cout << std::endl;
    printTree(root->left);
    printTree(root->right);
}

void printLevelWise(BinaryTreeNode<int> *root) {
    std::queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        std::cout << front->data << ":";

        if (front->left) {
            std::cout << "L:" << front->left->data;

            pendingNodes.push(front->left);
        }
        else {
            std::cout << "L:" << -1;
        }

        if (front->right) {
            std::cout << ",R:" << front->right->data;

            pendingNodes.push(front->right);
        }
        else {
            std::cout << ",R:" << -1;
        }

        std::cout << std::endl;
    }
}

int countNodes(BinaryTreeNode<int> *root) {
    if (!root) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if (!root) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    bool check {false};

    check = isNodePresent(root->left, x);

    if (check == true) {
        return check;
    }

    check = isNodePresent(root->right, x);

    return check;
}

int height(BinaryTreeNode<int>* root) {
    if (!root) {
        return 0;
    }

    int leftCount {1 + height(root->left)};
    int rightCount {1 + height(root->right)};
    
    return leftCount > rightCount ? leftCount : rightCount;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (!root) {
        return;
    }

    BinaryTreeNode<int> *temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }

    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

int main() {
    // BinaryTreeNode<int> *root  {new BinaryTreeNode<int>(1)};
    // BinaryTreeNode<int> *node1 {new BinaryTreeNode<int>(2)};
    // BinaryTreeNode<int> *node2 {new BinaryTreeNode<int>(3)};

    // root->left = node1;
    // root->right = node2;

    // BinaryTreeNode<int> *root {takeInput()};
    BinaryTreeNode<int> *root {takeInputLevelWise()};

    // printTree(root);
    printLevelWise(root);

    std::cout << countNodes(root) << std::endl;
    std::cout << isNodePresent(root, 5) << std::endl;
    std::cout << height(root) << std::endl;

    inOrder(root);
    preOrder(root);
    postOrder(root);
    
    mirrorBinaryTree(root);

    delete root;

    return 0;
}

// Input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1- 1 
