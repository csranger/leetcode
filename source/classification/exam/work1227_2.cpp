//
// Created by zhaohailong on 2020/5/12.
//

/*
测试工程师正在测试某款新型扫地机器人。工程师设计了一个形如二叉树（根节点记为 root）的测试路径，扫地机器人自路径对应的根节点出发，
一直行进至路径尽头（即二叉树叶节点）。如果这个路口的左右子节点都非空，机器人选择左转或右转的概率相等；
 如果这个路口的左右子节点仅一侧非空，则机器人选择非空侧走。
工程师给每个路口标记了数字，并且仅在标记数字 target 的所有路口设置了监控摄像机。请问扫地机器人被监控至少拍到一次的概率是多少？

输入：root = [1,2,3,2,5,6,2], target = 2
输出：0.75

     1
   /   \
  2     3
 /\    / \
2  5  6   2


解释：数组按二叉树层次遍历的顺序记录了标记数字。从 1 出发，从左侧走到 2 的概率为 0.5（被拍到）, 从右侧走到 3 的概率为 0.5, 从 3 继续出发，
 走到 2 的概率为 0.5（被拍到），所以结果为 0.5 + 0.5 * 0.5 = 0.75
即：左侧分支被拍到的概率为 0.5（红色圈的 2 是 0.5，继续走到 2 或 5，不会增加被拍概率，也不会降低被拍概率），
 右侧分支被拍到的概率为 0.25（红色圈的 2），合计为 0.75



示例 2:
输入：root = [1,null,3,2,2], target = 2
输出：1.0
限制：1 <= 树的节点数 <= 10000
 */

#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

class Solution {
public:
    double Probability(TreeNode *root, int target)
    {
        int layer = 0;
        double probability = 0;
        Bfs(root, layer, target, probability);
        return probability;
    }

    void Bfs(TreeNode *node, int layer, int &target, double &probability)
    {
        queue<pair<TreeNode *, int>> qe;
        qe.push(make_pair(node, layer));

        while (!qe.empty()) {
            TreeNode *tempNode = qe.front().first;
            int tempLayer = qe.front().second;
            qe.pop();
            if (tempNode->val == target) {
                probability += pow(0.5, tempLayer);
            }

            if (tempNode->val != target && tempNode->left != nullptr) {
                qe.push(make_pair(tempNode->left, tempLayer + 1));
            }
            if (tempNode->val != target && tempNode->right != nullptr) {
                qe.push(make_pair(tempNode->right, tempLayer + 1));
            }
        }
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(2);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(2);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    // test1
    Solution s;
    int target = 2;
    cout << s.Probability(&a, target) << endl;

    // test2
    int target2 = 1;
    cout << s.Probability(&a, target2) << endl;

    // test3
    int target3 = 3;
    cout << s.Probability(&a, target3) << endl;

    return 0;
}