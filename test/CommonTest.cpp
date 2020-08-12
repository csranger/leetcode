#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        if (n < 3) {
            return dp[n];
        }

        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        　return dp[n];
    }
};