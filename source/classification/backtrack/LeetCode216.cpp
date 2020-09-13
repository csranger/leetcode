//
// Created by zhaohailong on 2020/9/11.
//

/*
找出所有相加之和为n 的k个数的组合。组合中只允许含有 1 -9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCombination;
    int N;
    int K;
    vector<int> choose;

    // 和为 n 的 k 个数
    vector<vector<int>> combinationSum3(int k, int n) {
        K = k;
        N = n;

        int step = 0;
        int sum = 0;
        Backtrack(1, step, choose, sum);
        return allCombination;
    }

    void Backtrack(int start, int step, vector<int> &choose, int &sum) {
        if (step == K && sum == N) {
            allCombination.push_back(choose);
        }
        if (step > K || sum > N || start > 9) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            sum += i;
            choose.emplace_back(i);
            Backtrack(i + 1, step+1, choose, sum);
            choose.pop_back();
            sum -= i;
        }
    }
};

int main() {
    int k = 3, n = 7;
    Solution s;
    vector<vector<int>> ret = s.combinationSum3(k, n);
    for (auto &it:ret) {
        for (int i = 0; i < it.size(); i++) {
            cout << it[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}