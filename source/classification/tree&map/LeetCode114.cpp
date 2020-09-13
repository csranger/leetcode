//
// Created by zhaohailong on 2020/5/5.
//

/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

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
        if (root == nullptr) return;
        vector<TreeNode *> allNodes;
        Preorder(root, allNodes);
        for (int i = 0; i < allNodes.size() - 1; i++) {
            allNodes[i]->left = nullptr;
            allNodes[i]->right = allNodes[i + 1];
        }
    }

    void Preorder(TreeNode *node, vector<TreeNode *> &allNodes)
    {
        if (node == nullptr) return;

        allNodes.push_back(node);

        Preorder(node->left, allNodes);
        Preorder(node->right, allNodes);
    }
};

int main()
{
    TreeNode *t = nullptr;
    Solution s;
    s.flatten(t);
}










