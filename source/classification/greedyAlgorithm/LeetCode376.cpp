//
// Created by zhaohailong on 2020/6/10.
//

/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，
第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wiggle-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include <iostream>

using namespace std;

//贪心：当序列有一段连续的递增(或递减时)，为形成摇摆序列，我们只需要保留这些连续的递增(或递减时)的首尾元素，
//这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素。

enum State {
    BEGIN = 0,
    UP,
    DOWN
};

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int state = BEGIN;
        int ret = 1;        // 摇摆序列最大长度

        // 判断 nums[i] 的状态
        for (int i = 1; i < nums.size(); i++) {
            switch (state) {    // state 表示上一个元素的状态
                case BEGIN:
                    if (nums[i] > nums[i - 1]) {
                        ret++;
                        state = UP;
                    } else if (nums[i] < nums[i - 1]) {
                        ret++;
                        state = DOWN;
                    }
                    break;
                case UP:
                    if (nums[i] < nums[i - 1]) {
                        ret++;
                        state = DOWN;
                    }
                    break;
                case DOWN:
                    if (nums[i] > nums[i - 1]) {
                        ret++;
                        state = UP;
                    }
                    break;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> a = {1, 7, 4, 9, 2, 5};
    Solution s;
    cout << s.wiggleMaxLength(a) << endl;
}













