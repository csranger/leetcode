//
// Created by zhaohailong on 2020/5/6.
//

/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        queue<pair<TreeNode *, int>> qe;//宽搜队列<结点，层数>
        if (root != nullptr) {
            qe.push(make_pair(root, 0));
        }

        while (!qe.empty()) {
            TreeNode *node = qe.front().first;
            int layer = qe.front().second;
            qe.pop();

            if (ret.size() == layer) {      // 第 layer 层第一个结点
                ret.push_back(node->val);
            } else {                        // 第 layer 层非第一个结点
                ret[layer] = node->val;     // 更新layer层结点值
            }

            if (node->left != nullptr) {
                qe.push(make_pair(node->left, layer + 1));
            }
            if (node->right != nullptr) {
                qe.push(make_pair(node->right, layer + 1));
            }
        }
        return ret;
    }
};