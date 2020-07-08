//
// Created by zhaohailong on 2020/6/13.
//

/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
分析
1432219 -> 432219   删除 index 0
1432219 -> 132219   删除 index 1  最优解
1432219 -> 142219   删除 index 2
1432219 -> 143219   删除 index 3
1432219 -> 143219   删除 index 4
1432219 -> 143229   删除 index 5
1432219 -> 143221   删除 index 6

1. 若去掉某一位数字，为使得新数字最小，尽可能让新数字优先最高位最小
2. 从高位到低位遍历，如果当前数字(单调栈top)大于下一位数字，则把当前数字去掉
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        vector<int> increaseStack;      // 使用vector当做栈，因为可以遍历
        for (int i = 0; i < num.size(); i++) {
            int number = num[i] - '0';
            while (increaseStack.size() != 0 && increaseStack[increaseStack.size() - 1] > number && k > 0) {
                increaseStack.pop_back();
                k--;
            }
            if (number == 0 && increaseStack.size() == 0) { // 0在字符串前面可忽略
                continue;
            }
            increaseStack.push_back(number);
        }

        // 栈不空，k>0，仍然可以删数字，则从头往后删除 "12345"
        while (increaseStack.size() != 0 && k > 0) {
            increaseStack.pop_back();
            k--;
        }

        // 将栈中元素从头遍历放入 result
        string ret;
        for (int i = 0; i < increaseStack.size(); i++) {
            ret.append(1, '0' + increaseStack[i]);
        }

        if (ret == "") {
            return "0";
        }
        return ret;
    }
};

int main()
{
    string num = "1432219";
    Solution s;
    string ret = s.removeKdigits(num, 3);
    cout << ret << endl;
    return 0;
}