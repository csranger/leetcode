//
// Created by zhaohailong on 2020/5/6.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

class Solution {
public:
    void flatten(TreeNode *root)
    {
        TreeNode *last;
        Preorder(root, last);
    }

    // 以node为跟结点的树已经展开，last为此树的末结点
    void Preorder(TreeNode *node, TreeNode *&last)
    {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            last = node;
            return;
        }

        TreeNode *left = node->left;    // 备份左右指针
        TreeNode *right = node->right;
        TreeNode *leftLast = nullptr;
        TreeNode *rightLast = nullptr;

        if (left != nullptr) {
            Preorder(left, leftLast); // 左子树展开好了
            node->left = nullptr;
            node->right = left;
            last = leftLast;
        }
        if (right != nullptr) {
            Preorder(right, rightLast);
            if (leftLast != nullptr) {
                leftLast->right = right;
            }
            last = rightLast;
        }

    }
};