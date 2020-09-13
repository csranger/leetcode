//
// Created by zhaohailong on 2020/9/12.
//

/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
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
    vector<double> avg;
    vector<double> averageOfLevels(TreeNode *root) {
        LevelOrder(root);
        return avg;
    }

    void LevelOrder(TreeNode *root) {
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            long long sum = 0;
            const int size = Q.size();
            for (int i = 0; i < size; i++) {
                sum += Q.front()->val;
                if (Q.front()->left != nullptr) Q.push(Q.front()->left);
                if (Q.front()->right != nullptr) Q.push(Q.front()->right);
                Q.pop();
            }
            avg.emplace_back(sum / (1.0 * size));
        }
    }
};