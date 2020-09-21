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
    vector<vector<int>> ans;
    vector<int> vec;

    vector<vector<int>> subsets(vector<int> &nums) {
        Backtrack(nums, 0);
        return ans;
    }

    void Backtrack(vector<int> &nums, int start) {
        if (start == nums.size()) {
            ans.push_back(vec);
            return;
        }

        // 选择当前位置
        vec.push_back(nums[start]);
        Backtrack(nums, start + 1);
        // 不选择当前位置
        vec.pop_back();
        Backtrack(nums, start + 1);

    }
};