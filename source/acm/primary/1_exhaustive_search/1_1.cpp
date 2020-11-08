//
// Created by zhaohailong on 2020/11/9.
//

// DFS
// 给定整数 a1、a2、...、an，判断是否从中可以选出若干数，使他们的和恰好为 k
// 限制条件
// 1 <= n <= 20
// -10^8 <= a(i) <= 10^8
// -10^8 <= k <= 10^8

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n_;
    vector<int> a_;
    int k_;

    bool solve (int n, vector<int> &a, int k) {
        n_ = n;
        a_.assign(a.begin(), a.end());  //元素赋值到当前的vector容器中，这个容器会清除掉vector容器中以前的内容
        k_ = k;
        return dfs(0, 0);
    }

    // 已经从前a_的前 i 项得到了和 sum，对第 i 项之后进行分支
    bool dfs(int i, int sum) {
        if (i == n_) return sum == k_;
        if (dfs(i + 1, sum)) return true;
        if (dfs(i + 1, sum + a_[i])) return true;
        return false;
    }
};

int main() {
    int n = 4;
    vector<int> a = {1, 2, 4, 7};
    int k = 21;
    Solution s;
    cout << s.solve(n, a, k) << endl;
    return 0;
}



