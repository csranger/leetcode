//
// Created by zhaohailong on 2020/9/10.
//

/*
给定一个数组candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。

candidates中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。
示例1:

输入: candidates =[10,1,2,7,6,1,5], target =8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例2:

输入: candidates =[2,5,2,1,2], target =5,
所求解集为:
[
 [1,2,2],
 [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> m_candidates;
    int m_target;
    set<vector<int>> allCandidates;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        m_candidates = candidates;
        m_target = target;
        int sum = 0;
        vector<int> choose;
        Backtrack(0, sum, choose);
        vector<vector<int>> ret;
        for (auto &it : allCandidates) {
            ret.emplace_back(it);
        }
        return ret;
    }

    void Backtrack(int start, int &sum, vector<int> &choose)
    {
        if (sum == m_target) {
            allCandidates.insert(choose);
            return;
        }
        if (sum > m_target || start >= m_candidates.size()) {
            return;
        }

        for (int i = start; i < m_candidates.size(); i++) {
            sum += m_candidates[i];
            choose.emplace_back(m_candidates[i]);
            Backtrack(i + 1, sum, choose);
            choose.pop_back();
            sum -= m_candidates[i];
        }
    }
};