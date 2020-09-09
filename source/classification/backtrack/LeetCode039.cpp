//
// Created by zhaohailong on 2020/9/9.
//

/*
给定一个无重复元素的数组candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。

candidates中的数字可以无限制重复被选取。

说明：

所有数字（包括target）都是正整数。
解集不能包含重复的组合。
示例1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> allCombines;
    vector<int> combine;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        Backtrack(candidates, 0, target, 0);
        return allCombines;
    }


    void Backtrack(vector<int> &candidates, int start, const int target, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            allCombines.push_back(combine);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            combine.push_back(candidates[i]);
            Backtrack(candidates, i, target, sum);
            sum -= candidates[i];
            combine.pop_back();
        }
    }
};
