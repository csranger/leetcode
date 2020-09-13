//
// Created by zhaohailong on 2020/5/4.
//

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <cstdio>
#include <iostream>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ret = nullptr;
        vector<TreeNode *> ppath;
        vector<TreeNode *> qpath;
        vector<TreeNode *> visit;
        int finish = 0;
        Preorder(root, visit, ppath, p, finish);
        finish = 0;
        visit.clear();
        Preorder(root, visit, qpath, q, finish);
        int pathLen = ppath.size() < qpath.size() ? ppath.size() : qpath.size();
        for (int i = 0; i < pathLen; i++) {
            if (ppath[i] != nullptr && qpath[i] != nullptr && ppath[i] == qpath[i]) {
                ret = ppath[i];
            } else {
                break;
            }
        }
        return ret;
    }

    // 获取跟结点 node 到 target 结点之间的路径
    void Preorder(TreeNode *node, vector<TreeNode *> &visit, vector<TreeNode *> &path, TreeNode *target, int &finish)
    {
        if (node == nullptr || finish == 1) return;

        visit.push_back(node);
        if (node == target) {
            finish = 1;
            path = visit;
        }

        Preorder(node->left, visit, path, target, finish);
        Preorder(node->right, visit, path, target, finish);

        visit.pop_back();
    }
};

int main()
{
    /*
               3
             /   \
            5     1
           / \   / \
          6  2  0   8
            / \
           7  4
     */

    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode g(8);
    TreeNode h(7);
    TreeNode i(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    e.left = &h;
    e.right = &i;

    Solution ss;
    vector<TreeNode *> visit;
    vector<TreeNode *> path;
    int finish = 0;
    ss.Preorder(&a, visit, path, &i, finish);

    for (int i = 0; i < path.size(); i++) {
        cout << "[" << path[i]->val << "] ";
        if (i < path.size() - 1) {
            cout << "-> ";
        }
    }
    cout << "\n";
    cout << "4 and 6 : \n";
    cout << ss.lowestCommonAncestor(&a, &d, &i)->val << endl;

    /*
     1
    /
   2
     */
    TreeNode aa(1);
    TreeNode bb(2);
    aa.left = &bb;
    cout << ss.lowestCommonAncestor(&aa, &bb, &aa)->val << endl;


    return 0;
}