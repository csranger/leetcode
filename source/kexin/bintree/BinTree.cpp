//
// Created by zhaohailong on 2020/5/11.
//

/*
1. 二叉查找树性质：
    (1) 左子树不为空，左子树上所有结点的值都小于跟结点的值
    (2) 右子树不为空，右子树上所有结点的值都大于跟结点的值
    (3) 二叉查找树的中序遍历是从小到大的
 */

// 数据结构与二叉树完全相同
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};