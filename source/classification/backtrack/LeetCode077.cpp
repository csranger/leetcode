//
// Created by zhaohailong on 2020/9/8.
//

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
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
    set<int> used;
    int N;
    vector<vector<int>> combines;

    vector<vector<int>> combine(int n, int k) {
        N = k;
        vector<int> vec;
        Backtrack(0, vec);
        return combines;
    }

    void Backtrack(int size, vector<int> &vec) {
        if (size == N) {
            combines.push_back(vec);
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (used.find(i) == used.end()) vec.emplace_back(i);
            used.insert(i);
            Backtrack(size + 1, vec);
            auto it = begin(vec);
            vec.erase(it);
            used.erase(i);
        }
    }
};

int main()
{
    int n = 4;
    int k = 2;
    Solution s;
    vector<vector<int>> ret = s.combine(n, k);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << endl;
        }
    }


    return 0;
}




