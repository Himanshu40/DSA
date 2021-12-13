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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if (!root) {
        return root;
    }
    
    TreeNode<int> *nextLarger {nullptr};

    if (root->data > x) {
        nextLarger = root;
    }
    
    for (int i {0}; i < root->children.size(); ++i) {
        TreeNode<int> *temp {getNextLargerElement(root->children[i], x)};
    
        if (!nextLarger) {
            nextLarger = temp;
        }
        else if (temp && temp->data < nextLarger->data) {
            nextLarger = temp;
        }
    }
    
    return nextLarger;
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
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}