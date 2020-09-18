//
// Created by zhaohailong on 2020/5/29.
//

/*
二叉树的深度遍历

              1
             / \
            2   5
           / \   \
          3   4   6

    - 前序遍历: 1->2->3->4->5->6 当前结点->左子树->右子树
    - 中序遍历: 3->2->4->1->5->6 左子树->当前结点->右子树
    - 后序遍历: 3->4->2->6->5->1 左子树->右子树->当前结点
 */

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

// 前序遍历
void PreorderPrint(TreeNode *node, int layer) {
    if (node == nullptr) return;

    for (int i = 0; i < layer; i++) {
        printf("-----");
    }
    printf("[%d]\n", node->val);

    PreorderPrint(node->left, layer + 1);
    PreorderPrint(node->right, layer + 1);
}

// 中序遍历
void InorderPrint(TreeNode *node, int layer) {
    if (!node) return;

    InorderPrint(node->left, layer + 1);

    for (int i = 0; i < layer; i++) {
        printf("-----");
    }
    printf("[%d]\n", node->val);

    InorderPrint(node->right, layer + 1);
}

// 后序遍历
void PostorderPrint(TreeNode *node, int layer) {
    if (!node) return;

    PostorderPrint(node->left, layer + 1);
    PostorderPrint(node->right, layer + 1);

    for (int i = 0; i < layer; i++) {
        printf("-----");
    }
    printf("[%d]\n", node->val);
}

// 层序遍历，此时 layer 相当于搜索里的 step
void LevelorderPrint(TreeNode *node, int layer) {
    queue<TreeNode *> Q;
    Q.push(node);

    while (!Q.empty()) {
        TreeNode *temp = Q.front();

        Q.pop();

        // 取出队列的结点进行处理
        for (int i = 0; i < layer; i++) {
            printf("-----");
        }
        printf("[%d]\n", temp->val);
        layer++;

        if (temp->left != nullptr) Q.push(temp->left);
        if (temp->right != nullptr) Q.push(temp->right);
    }
}

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    cout << "前序遍历:" << endl;
    PreorderPrint(&a, 0);

    cout << "层次遍历:" << endl;
    LevelorderPrint(&a, 0);

    return 0;
}