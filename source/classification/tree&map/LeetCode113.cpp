//
// Created by zhaohailong on 2020/5/3.
//

/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> path;
        vector<int> visit;
        int s = 0;
        Preorder(root, visit, path, s, sum);
        return path;
    }

    void Preorder(TreeNode *node, vector<int> &visit, vector<vector<int>> &path, int &sum, int &target) {
        if (node == nullptr) {
            return;
        }

        // preorder 在这里处理
        visit.push_back(node->val);
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr && sum == target) {
            path.push_back(visit);
        }

        Preorder(node->left, visit, path, sum, target);
        Preorder(node->right, visit, path, sum, target);

        visit.pop_back();
        sum -= node->val;
    }
};