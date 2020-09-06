//
// Created by zhaohailong on 2020/9/6.
//

/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> path;
        if (root == nullptr) {
            return path;
        }
        LevelOrder(root, path);
        reverse(path.begin(), path.end());
        return path;
    }

    void LevelOrder(TreeNode *node, vector<vector<int>> &path) {
        queue<TreeNode *> Q;
        Q.push(node);

        while (!Q.empty()) {
            path.push_back(vector<int>());
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = Q.front();
                Q.pop();
                path[path.size() - 1].push_back(temp->val);
                if (temp->left != nullptr) Q.push(temp->left);
                if (temp->right != nullptr) Q.push(temp->right);
            }
        }
    }
};