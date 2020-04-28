//
// Created by zhaohailong on 2020/4/26.
//

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 3, 0);
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2) {
            return dp[n];
        }
        for (int i = 3; i <= n; i++) {
            dp[n] = dp[n - 2] + dp[n - 1];
        }
        return dp[n];
    }
};