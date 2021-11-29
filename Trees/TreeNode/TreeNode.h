#include <vector>

using std::vector;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T> *> children;

        TreeNode(T data) : data {data} {}
};
