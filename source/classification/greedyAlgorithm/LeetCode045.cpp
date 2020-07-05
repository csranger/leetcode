//
// Created by zhaohailong on 2020/7/5.
//

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() < 2) {
            return 0;
        }
        int curMaxIndex = nums[0];      // 当前跳跃点可跳最远位置
        int nextMaxIndex = nums[0];     // 跳跃后在下一个跳跃点可调最远位置
        int minJump = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > curMaxIndex) {      // 在当前位置和当前跳跃点可跳最远位置遍历后才确定跳到哪里
                minJump++;
                curMaxIndex = nextMaxIndex;
            }
            if (nextMaxIndex < i + nums[i]) {
                nextMaxIndex = i + nums[i];
            }
        }
        return minJump;

    }
};