//
// Created by zhaohailong on 2020/9/19.
//

/*
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *node) {
        return GetLeftSum(node, false);
    }

    // 返回以node结点为跟结点的左子树之和，isLeft表示当前node结点是否是上一结点的左结点
    int GetLeftSum(TreeNode *node, bool isLeft) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr && isLeft == true) {
            return node->val;
        }
        return GetLeftSum(node->left, true) + GetLeftSum(node->right, false);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    Solution s;
    cout << s.sumOfLeftLeaves(&a) << endl;

    return 0;
}