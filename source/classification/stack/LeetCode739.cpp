//
// Created by zhaohailong on 2020/9/9.
//

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。





以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为[2,1,5,6,2,3]。





图中阴影部分为所能勾勒出的最大矩形面积，其面积为10个单位。



示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> wait(T.size(), 0);
        // 栈
        vector<int> monoStack;
        for (int i = 0; i < T.size(); i++) {
            if (monoStack.size() > 0 && T[monoStack[monoStack.size()-1]] < T[i]) {
                wait.push_back(i - monoStack[monoStack.size() - 1]);
                monoStack.pop_back();
            }
            monoStack.push_back(i);
        }
        return wait;
    }
};

int main()
{
    vector<int> b = {3, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    s.dailyTemperatures(b);

    return 0;
}