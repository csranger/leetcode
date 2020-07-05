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

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() <= k) {
            return "0";
        }

        while (k > 0) {
            num = RemoveOnce(num);
            k--;
        }
        // 去除字符串前面的0
        int pos = FirstNot0Index(num);
        string ret = pos == -1 ? "0" : num.substr(pos);
        return ret;
    }

    string RemoveOnce(const string &num)
    {
        string ret;
        int i = 0;
        for (i = 0; i < num.size() - 1; i++) {
            if (num[i] > num[i + 1]) {
                break;
            }
            ret += num[i];
        }
        if (i < num.size() - 1) {
            ret += num.substr(i + 1);
        }
        return ret;
    }

    int FirstNot0Index(const string &num)
    {
        int ret = -1;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != '0') {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;

    string str = "100";
    cout << s.FirstNot0Index(str) << endl;

    string str2 = "12";
    cout << s.FirstNot0Index(str2) << endl;

    string str3 = "0000";
    cout << s.FirstNot0Index(str3) << endl;
}