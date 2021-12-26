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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

class MinMax {
    public:
    int minimum;
    int maximum;
};

class BSTHeight {
    public:
    bool isBST;
    int height;
};

pair<MinMax, BSTHeight> largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
    if (!root) {
        pair<MinMax, BSTHeight> answer;

        answer.first.minimum = INT_MAX;
        answer.first.maximum = INT_MIN;

        answer.second.isBST = true;
        answer.second.height = 0;

        return answer;
    }

    pair<MinMax, BSTHeight> lPair {largestBSTSubtreeHelper(root->left)};
    pair<MinMax, BSTHeight> rPair {largestBSTSubtreeHelper(root->right)};

    int maximum = max(lPair.first.maximum, rPair.first.maximum);
    int minimum = min(lPair.first.minimum, rPair.first.minimum);
    int height = max(lPair.second.height, rPair.second.height);

    pair<MinMax, BSTHeight> answer;

    if ((lPair.second.isBST && rPair.second.isBST) && (root->data > lPair.first.maximum && root->data < rPair.first.minimum)) {
        answer.first.minimum = min(minimum, root->data);
        answer.first.maximum = max(maximum, root->data);

        answer.second.isBST = true;
        answer.second.height = 1 + height;

        return answer;
    }
    
    answer.second.isBST = false;
    answer.second.height = height;

    return answer;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTSubtreeHelper(root).second.height;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}