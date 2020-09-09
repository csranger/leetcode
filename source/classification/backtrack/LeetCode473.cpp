//
// Created by zhaohailong on 2020/4/19.
//

/*
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。
 不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在0到10^9之间。
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

        int sides[4] = { 0 };

        return Backtrack(nums, sides, 0, sum / 4);
    }

    // nums 的第 i 跟火柴放入 sides 的 4 条边上
    bool Backtrack(vector<int> &nums, int sides[], int i, int target)
    {
        // 最后一根火柴放完进行判断
        if (i >= nums.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }

        // 每根火柴分别放在四条边的哪一边？
        for (int j = 0; j < 4; j++) {
            if (sides[j] + nums[i] > target) {
                continue;
            }

            sides[j] += nums[i];    // nums 的第 i 根火柴放入 sides 的第 j 条边上，接着放入第 i + 1 根火柴
            if (Backtrack(nums, sides, i + 1, target)) {
                return true;
            }

            sides[j] -= nums[i];    // nums 的第 i 根火柴放入 sides 的第 j 条边上，无法成功则撤回放入 j + 1 条边上
        }

        return false;
    }
};