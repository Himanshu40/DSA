#include <iostream>
#include "binaryTreeNode.h"

class BST {
    BinaryTreeNode<int> *root;

    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            return nullptr;
        }

        if (data < root->data) {
            root->left = remove(root->left, data);
            return root;
        }
        else if (data > root->data) {
            root->right = remove(root->right, data);
            return root;
        }
        else {
            if (!root->left && !root->right) {
                delete root;

                return nullptr;
            }
            else if (!root->right) {
                BinaryTreeNode<int> *temp {root->left};
                root->left = nullptr;

                delete root;
                return temp;
            }
            else if (!root->left) {
                BinaryTreeNode<int> *temp {root->right};
                root->right = nullptr;

                delete root;
                return temp;
            }
            else {
                BinaryTreeNode<int> *minNode {root->right};

                while (minNode) {
                    minNode = minNode->left;
                }

                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = remove(root->right, rightMin);

                return root;
            }
        }
    }

    void print(BinaryTreeNode<int> *root) {
        if (!root) {
            return;
        }

        std::cout << root->data << ":";

        if (root->left) {
            std::cout << "L:" << root->left->data << ",";
        }

        if (root->right) {
            std::cout << "R:" << root->right->data;
        }

        std::cout << std::endl;
        print(root->left);
        print(root->right);
    }

    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            BinaryTreeNode<int> *answer {new BinaryTreeNode<int>(data)};

            return answer;
        }

        if (data <= root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    bool search(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            return false;
        }

        if (root->data == data) {
            return true;
        }

        if (data < root->data) {
            return search(root->left, data);
        }

        return search(root->right, data);
    }
   
   public:
    BST() : root {nullptr} {}

    ~BST() {delete root;}

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        root = remove(root, data);
    }

    void print() { 
        print(root);
    }

    void insert(int data) { 
        root = insert(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }
};