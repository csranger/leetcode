//
// Created by zhaohailong on 2020/9/8.
//

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入:n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> combile;
        vector<vector<int>> combiles;
        BackTrack(combile, 1, n, k, combiles);
        return combiles;
    }

    void BackTrack(vector<int> &combile, int start, const int N, const int target,
                   vector<vector<int>> &combiles)
    {
        if (combile.size() == target) {
            combiles.push_back(combile);
            return;
        }

        // 关键是从 start 开始搜索，比它小的剪枝，这样就不需要使用 used数组进行记录了
        for (int i = start; i <= N; i++) {
            combile.push_back(i);
            BackTrack(combile, i + 1, N, target, combiles);
            combile.pop_back();
        }
    }
};



