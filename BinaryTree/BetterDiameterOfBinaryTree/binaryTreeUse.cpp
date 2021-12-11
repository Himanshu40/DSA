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

std::pair<int, int> heightDiameter(BinaryTreeNode<int> *root) {
    if (!root) {
        std::pair<int, int> p(0, 0);

        return p;
    }

    std::pair<int, int> leftAns  {heightDiameter(root->left)};
    std::pair<int, int> rightAns {heightDiameter(root->right)};

    int ld {leftAns.second};
    int lh {leftAns.first};

    int rd {rightAns.first};
    int rh {rightAns.first};

    int height   {1 + std::max(lh, rh)};
    int diameter {std::max(lh + rh, std::max(ld, rd))};

    std::pair<int, int> p(height, diameter);

    return p;
}

int main() {
    BinaryTreeNode<int> *root {takeInputLevelWise()};

    printLevelWise(root);

    std::pair<int, int> p {heightDiameter(root)};
    std::cout << "Height: " << p.first << std::endl;
    std::cout << "Diameter: " << p.second << std::endl;

    delete root;
 
    return 0;
}

// Input : 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
