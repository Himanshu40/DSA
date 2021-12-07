#include <iostream>
#include <queue>
#include <vector>
#include <climits>

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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    TreeNode<int> *maxNode {root};
    TreeNode<int> *secondMaxNode {nullptr};
    int max {root->data};

    while (!pendingNodes.empty()) {
        TreeNode<int> *front {pendingNodes.front()};
        pendingNodes.pop();

        for (int i {0}; i < front->children.size(); ++i) {
            pendingNodes.push(front->children[i]);
        }
        
        if (front->data == maxNode->data)
            continue;
        
        if (front->data > maxNode->data) {
            secondMaxNode = maxNode;
            maxNode = front;
        }
        else if (secondMaxNode == nullptr || secondMaxNode->data < front->data) {
            secondMaxNode = front;
        }
    }

    return secondMaxNode;
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

    return 0;
}
