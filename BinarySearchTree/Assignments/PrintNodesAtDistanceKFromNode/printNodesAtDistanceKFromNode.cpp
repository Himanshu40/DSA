#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printDepth(BinaryTreeNode<int> *root, int k) {
    if (!root) {
        return;
    }

    if (k == 0) {
        cout << root->data;
        cout << endl;
    }

    printDepth(root->left, k - 1);
    printDepth(root->right, k - 1);
}

int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int node, int k) {
    if (!root) {
        return -1;
    }
    
    if (root->data == node) {
        printDepth(root, k);

        return 0;
    }

    int lD {nodesAtDistanceKHelper(root->left, node, k)};

    if (lD != -1) {
        if (lD + 1 == k) {
            cout << root->data;
        }
        else {
            printDepth(root->right, k - lD - 2);
        }
        
        return lD + 1;
    }

    int rD {nodesAtDistanceKHelper(root->right, node, k)};

    if (rD != -1) {
        if (rD + 1 == k) {
            cout << root->data;
        }
        else {
            printDepth(root->left, k - rD - 2);
        }
        
        return rD + 1;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    // int targetNode, k;
    // cin >> targetNode >> k;
    // nodesAtDistanceK(root, targetNode, k);

    printDepth(root, 2);
    delete root;
}