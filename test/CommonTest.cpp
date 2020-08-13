#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode *root) {
        return max(Postorder(root).first, Postorder(root).second);
    }

    // 含有当前根结点的最大值，不含当前跟结点的最大值
    pair<int, int> Postorder(TreeNode *node) {
        if (node == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = Postorder(node->left);
        pair<int, int> right = Postorder(node->right);

        return {node->val + left.second + right.second,
                max(left.first, left.second) + max(right.first, right.second)};
    }
};