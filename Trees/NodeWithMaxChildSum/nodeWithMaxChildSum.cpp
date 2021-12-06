#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if (!root) {
        return root;
    }

    int maxSum {0};
    TreeNode<int> *maxSumNode;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        TreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        int count {front->data};

        for (int i {0}; i < front->children.size(); ++i) {
            count += front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }

        if (count > maxSum) {
            maxSum = count;
            maxSumNode = front;
        }
    }

    return maxSumNode;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}