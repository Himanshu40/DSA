#include <iostream>
#include <queue>

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

pair<bool, int> isBalancedHelper(BinaryTreeNode<int> *root) {
    if (!root) {
        pair<bool, int> p(true, 0);

        return p;
    }

    pair<bool, int> lTree {isBalancedHelper(root->left)};
    pair<bool, int> rTree {isBalancedHelper(root->right)};

    bool lBalanceCheck {lTree.first};
    int lHeight {lTree.second};

    bool rBalanceCheck {rTree.first};
    int rHeight {rTree.second};

    int maxHeight {max(lHeight, rHeight)};

    pair<bool, int> ans;
    if (lBalanceCheck == true && rBalanceCheck == true) {
        if ((maxHeight - 1) <= 1) {
            ans.first = true;
        }
    }
    else {
        ans.first = false;
    }

    ans.second = maxHeight + 1;

    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	return isBalancedHelper(root).first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");

    return 0;
}