//
// Created by zhaohailong on 2020/5/14.
//

/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string data;
        Preorder(root, data);
        return data;
    }

    void Preorder(TreeNode *node, string &data)
    {
        if (node == nullptr) {
            return;
        }

        string strVal;
        Int2String(node->val, strVal);
        data += strVal;

        Preorder(node->left, data);
        Preorder(node->right, data);
    }

    // 整形转字符串: 从尾部逐个取数字转成char，添加到字符串上，然后字符串反转
    void Int2String(int val, string &valStr)
    {
        string tmp;
        while (val != 0) {
            tmp += (val % 10 + '0');
            val = val / 10;
        }
        for (int i = tmp.size() - 1; i >= 0; i--) {
            valStr += tmp[i];
        }
        valStr += '#';
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0) {
            return 0;
        }
        vector<TreeNode *> nodeVec;
        int val = 0;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                nodeVec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + data[i] - '0';
            }
        }
        for (int i = 1; i < nodeVec.size(); i++) {
            InserNode(nodeVec[0], nodeVec[i]);
        }
        return nodeVec[1];
    }

    // 二叉查找树插入结点：以 node 为根结点的查找树上插入 insertNode 结点，返回插入此结点后的查找树的跟结点
    TreeNode *InserNode(TreeNode *node, TreeNode *insertnode)
    {
        if (node == nullptr) {
            return insertnode;
        }

        if (node->val < insertnode->val) {
            node->right = InserNode(node->right, insertnode);
        } else if (node->val > insertnode->val) {
            node->left = InserNode(node->left, insertnode);
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




int main()
{
    /*

              5
             / \
            4   8
           /   / \
          1  6     9
     */
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(9);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;

    Codec s;
    string str;
    str += 5 + '0';
    cout << str << endl;
}