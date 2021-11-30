#include <iostream>
#include <queue>
#include "TreeNode.h"

TreeNode<int> *takeInput() {
    int rootData;

    std::cout << "Enter root data: ";
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

TreeNode<int> *takeInputLevelWise() {
    int rootData;

    std::cout << "Enter root data: ";
    std::cin >> rootData;

    TreeNode<int> *root {new TreeNode<int>(rootData)};

    std::queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()) {
        TreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        std::cout << "Enter number of children of " << front->data << ": ";
        int numChild;

        std::cin >> numChild;

        for (int i {0}; i < numChild; ++i) {
            int childData;

            std::cout << "Enter " << i << "th child of " << front->data << ": ";
            std::cin >> childData;

            TreeNode<int> *child {new TreeNode<int>(childData)};
            front->children.push_back(child);

            pendingNodes.push(child);
        }
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

void printLevelWise(TreeNode<int>* root) {
    if (!root) {
        return;
    }

    std::queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()) {
        TreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        std::cout << front->data << ":";

        for (int i {0}; i < front->children.size(); ++i) {
            std::cout << front->children[i]->data;

            if (front->children.size() - i != 1) {
                std::cout << ",";
            }

            pendingNodes.push(front->children[i]);
        }

        std::cout << std::endl;
    }
}

int main() {
    // TreeNode<int> *root {new TreeNode<int>(1)};
    // TreeNode<int> *node1 {new TreeNode<int>(2)};
    // TreeNode<int> *node2 {new TreeNode<int>(3)};

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    // TreeNode<int> *root {takeInput()};
    // printTree(root);

    TreeNode<int> *root {takeInputLevelWise()};
    printLevelWise(root);

    return 0;
}
