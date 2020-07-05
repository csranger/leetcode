//
// Created by zhaohailong on 2020/5/15.
//

/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;
    int leftCount;

    TreeNode2(int x) : val(x), left(nullptr), right(nullptr), leftCount(0)
    {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ret;
        if (nums.size() < 1) {
            return ret;
        }
        vector<TreeNode2 *> nodeVec;
        for (int i = nums.size() - 1; i >= 0; i--){
            nodeVec.push_back(new TreeNode2(nums[i]));
        }
        int countSmall = 0;
        ret.push_back(countSmall);
        for (int i = 1; i < nodeVec.size(); i++) {
            countSmall = 0;
            InsertNode(nodeVec[0], nodeVec[i], countSmall);
            ret.push_back(countSmall);
        }
        vector<int> reverseRet;
        ReverseArray(ret, reverseRet);
        // delete new:that's why use nodeVec
        for (int i = 0; i < nodeVec.size(); i++) {
            delete nodeVec[i];
            nodeVec[i] = nullptr;
        }
        return reverseRet;
    }

    // 向 node 二叉查找树里插入结点 insertnode，并更新左子树数量，同时获取当前结点小于插入结点的数量
    TreeNode2 *InsertNode(TreeNode2 *node, TreeNode2 *insertnode, int &countSmall)
    {
        if (node == nullptr) {
            return insertnode;
        }
        if (insertnode->val > node->val) {
            countSmall += node->leftCount + 1;
            node->right = InsertNode(node->right, insertnode, countSmall);
        } else if (insertnode->val <= insertnode->val) {
            node->leftCount++;
            node->left = InsertNode(node->left, insertnode, countSmall);
        }
        return node;
    }

    // 逆序数组
    void ReverseArray(vector<int> &nums, vector<int> &ret)
    {
        for (int i = nums.size() - 1; i >= 0; i--) {
            ret.push_back(nums[i]);
        }
    }
};

int main()
{
    vector<int> a = {5, 2, 6, 1};
    vector<int> a2;
    Solution s;
    s.ReverseArray(a, a2);
    cout << a2.size() << endl;
    cout << a2[0] << endl;
    cout << a2[1] << endl;
    cout << a2[2] << endl;
    //
    cout << "test countSmaller " << endl;
    vector<int> ret = s.countSmaller(a);
    cout << ret.size() << endl;
    cout << ret[0] << endl;
    cout << ret[1] << endl;
    cout << ret[2] << endl;
    cout << ret[3] << endl;
}