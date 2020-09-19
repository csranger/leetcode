//
// Created by zhaohailong on 2020/9/19.
//

/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:

    vector<int> combination;
    set<vector<int>> allCombination;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visit(nums.size(), 0);
        Backtrack(nums, 0, visit);
        vector<vector<int>> ret;
        for (auto &it : allCombination) {
            ret.push_back(std::move(it));
        }
        return ret;
    }

    void Backtrack(vector<int>& nums, int step, vector<bool> &visit)
    {
        if (step == nums.size()) {
            allCombination.emplace(combination);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i]) {
                combination.push_back(nums[i]);
                visit[i] = 1;
                Backtrack(nums, step + 1, visit);
                combination.pop_back();
                visit[i] = 0;
            }
        }
    }
};