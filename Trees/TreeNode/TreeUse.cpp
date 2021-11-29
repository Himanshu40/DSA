#include <iostream>
#include "TreeNode.h"

TreeNode<int> *takeInput() {
    int rootData;

    std::cout << "Enter data: ";
    std::cin >> rootData;

    TreeNode<int> *root {new TreeNode<int>(rootData)};

    int n;

    std::cout << "Enter number of children of " << rootData << ": ";
    std::cin >> n;
    
    for (int i {0}; i < n; ++i) {
        TreeNode<int> *child {takeInput()};
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int> *root) {
    // Edge case not base case
    if (!root) {
        return;
    }

    std::cout << root->data << ":";

    for (int i {0}; i < root->children.size(); ++i) {
        std::cout << root->children[i]->data << " ";
    }

    std::cout << std::endl;

    for (int i {0}; i < root->children.size(); ++i) {
        printTree(root->children[i]);
    }
}

int main() {
    // TreeNode<int> *root {new TreeNode<int>(1)};
    // TreeNode<int> *node1 {new TreeNode<int>(2)};
    // TreeNode<int> *node2 {new TreeNode<int>(3)};

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int> *root {takeInput()};
    printTree(root);

    return 0;
}
