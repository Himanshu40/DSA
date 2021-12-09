template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(T data) 
            : data {data}, left {nullptr}, right {nullptr} {}

        ~BinaryTreeNode() {
            delete left;
            delete right;
        }
};
