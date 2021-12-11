#include <iostream>
#include <queue>
#include <climits>

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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    if (!root) {
        pair<int, int> p(INT_MAX, INT_MIN);

        return p;
    }

    pair<int, int> p1 {getMinAndMax(root->left)};
    pair<int, int> p2 {getMinAndMax(root->right)};
    
    int p1Min {p1.first};
    int p1Max {p1.second};

    int p2Min {p2.first};
    int p2Max {p2.second};

    int max {std::max(p1Max, p2Max)};
    int min {std::min(p1Min, p2Min)};

    pair<int, int> ans (std::max(max, root->data), std::min(min, root->data));

    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;

    return 0;
}
