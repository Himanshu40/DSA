#include <iostream>
#include <queue>
#include "binaryTreeNode.h"

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

int height(BinaryTreeNode<int> *root) {
    if (!root) {
        return 0;
    }

    int lHeight {1 + height(root->left)};
    int rHeight {1 + height(root->right)}; 

    return lHeight > rHeight ? lHeight : rHeight;
}

int diameter(BinaryTreeNode<int> *root) {
    if (!root) {
        return 0;
    }

    int option1 {height(root->left) + height(root->right)};
    int option2 {diameter(root->left)};
    int option3 {diameter(root->right)};

    return std::max(option1, std::max(option2, option3));
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



    delete root;

    return 0;
}

// Input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1- 1 
