#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 0);
        dp[0] = nums[0];
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() < 2) {
            return nums[0];
        }
        for (int i = 1; i, nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }

        int maxSubArray = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSubArray = max(maxSubArray, dp[i]);
        }
        return maxSubArray;
    }
};