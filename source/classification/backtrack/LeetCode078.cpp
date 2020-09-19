//
// Created by zhaohailong on 2020/4/19.
//

/*
给定一组不含重复元素的整数数组nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ret;
        vector<int> visit;      // 回溯时产生各个子集的数据
        ret.push_back(visit);       // 将空集push进入ret
        DFS(nums, visit, 0, ret);
        return ret;
    }

private:
    // 以 nums[i] 元素开始进行深度搜索；visit 用于保存路径上节点，每一个节点都有是否经过的选择
    void DFS(vector<int> &nums, vector<int> &visit, int i, vector<vector<int>> &ret) {
        if (i >= nums.size()) {
            return;
        }
        visit.push_back(nums[i]);
        ret.push_back(visit);  // 将当前生成的子集push进入ret
        DFS(nums, visit, i + 1, ret);     // 放入   nums[i] 元素继续递归
        visit.pop_back();                                    // 回溯操作
        DFS(nums, visit, i + 1, ret);     // 不放入 nums[i] 元素继续递归
    }
};