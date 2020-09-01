#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
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