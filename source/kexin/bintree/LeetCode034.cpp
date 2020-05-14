//
// Created by zhaohailong on 2020/5/11.
//

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret;
        int in = 0;
        BinarySearch(nums, target, in);
        if (in != 1) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        float target1 = target - 0.5;
        float target2 = target + 0.5;
        int left = BinarySearch(nums, target1, in);
        int right = BinarySearch(nums, target2, in);
        ret.push_back(left);
        ret.push_back(right - 1);
        return ret;
    }

    int BinarySearch(vector<int> &nums, float target, int &in)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] < target) {
                begin = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                in = 1;
                return mid;
            }
        }
        return begin;
    }
};



