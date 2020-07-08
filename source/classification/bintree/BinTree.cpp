//
// Created by zhaohailong on 2020/5/11.
//

/*
1. 二叉查找树性质：
    (1) 左子树不为空，左子树上所有结点的值都小于跟结点的值
    (2) 右子树不为空，右子树上所有结点的值都大于跟结点的值
    (3) 二叉查找树的中序遍历是从小到大的
 */

#include <cstdio>
// 数据结构与二叉树完全相同
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

// 二叉查找树插入结点：以 node 为根结点的查找树上插入 insertNode 结点，返回插入此结点后的查找树的跟结点
TreeNode *BinTreeInsertNode(TreeNode *node, TreeNode *insertNode)
{
    if (node == nullptr) {
        return insertNode;
    }

    if (node->val > insertNode->val) {
        node->left = BinTreeInsertNode(node->left, insertNode);
    } else if (node->val < insertNode->val) {
        node->right = BinTreeInsertNode(node->right, insertNode);
    }
    return node;
}

// 二叉查找树前序遍历
void Preorder(TreeNode *node, int layer)
{
    if (node == nullptr) return;

    for (int i = 0; i < layer; i++) {
        printf("----");
    }
    printf("[%d]\n", node->val);

    Preorder(node->left, layer + 1);
    Preorder(node->right, layer + 1);

}

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

    Preorder(&a, 0);

    return 0;
}