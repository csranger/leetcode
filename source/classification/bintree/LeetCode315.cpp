//
// Created by zhaohailong on 2020/5/15.
//

/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;
    int leftCnt;    // 小于当前结点值 val 的结点数量

    TreeNode2(int v) : val(v), left(nullptr), right(nullptr), leftCnt(0) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<TreeNode2 *> vec;
        // 从后向前构造二叉查找树
        for (int i = nums.size() - 1; i >= 0; i--) {
            vec.emplace_back(new TreeNode2(nums[i]));
        }
        TreeNode2 *root = nullptr;
        int countSmall = 0;
        vector<int> ret;
        for (auto &it: vec) {
            countSmall = 0;
            root = InsertNode(root, it, countSmall);
            ret.push_back(countSmall);
        }

        reverse(ret.begin(), ret.end());

        // free
        for (auto &it : vec) {
            delete it;
            it = nullptr;
        }

        return ret;

    }

    // 向 node 为跟结点的二叉树插入 insertNode 结点，返回插入后的二叉树跟结点
    // countSmall 表示比 insertNode 值小的个数
    static TreeNode2 *InsertNode(TreeNode2 *node, TreeNode2 *insertNode, int &countSmall) {
        if (node == nullptr) {
            return insertNode;
        }
        if (node->val >= insertNode->val) {
            node->leftCnt++;
            node->left = InsertNode(node->left, insertNode, countSmall);
        } else {
            countSmall += node->leftCnt + 1;
            node->right = InsertNode(node->right, insertNode, countSmall);
        }
        return node;
    }
};