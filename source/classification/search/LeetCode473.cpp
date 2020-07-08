//
// Created by zhaohailong on 2020/4/19.
//

/*
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。
 不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.size() < 4) {
            return false;
        }
        // 优化1：总和不是4的倍数，拼不成正方形
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        // 优化2：从大到小排序，默认从小到大;或 sort(nums.rbegin(), nums.rend());
        sort(nums.begin(), nums.end(), greater<int>());

        int visit[4] = { 0 };  // 放入火柴杆

        return Dfs(nums, visit, 0, sum / 4);
    }

private:
    bool Dfs(vector<int> &nums, int visit[], int i, int target)
    {
        if (i >= nums.size()) {
            return visit[0] == target && visit[1] == target && visit[2] == target && visit[3] == target;
        }

        for (int j = 0; j < 4; j++) {   // nums[i] 放在四个bucket里的哪边？，要求bucket[j] + nums[i] <= target
            if (visit[j] + nums[i] > target) {
                continue;
            }
            visit[j] += nums[i];    // nums[i] 火柴放在 j 桶，可以放则在此基础上继续进行深度搜索
            if (Dfs( nums, visit, target, i + 1)) {    // 如果深度搜索成功，则结束
                return true;
            }

            visit[j] -= nums[i];                       // 如果nums[i] 火柴放在 j 桶深度搜索不成功，则回溯这一步，试试放在 j+1 桶
        }
        return false;
    }
};