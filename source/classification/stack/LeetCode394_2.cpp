//
// Created by zhaohailong on 2020/9/22.
//

/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像3a或2[4]的输入。

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        int num = 0;
        string str;

        for (int i = 0; i < s.size(); i++) {
            // 当 s[i] 为 [ 时，将当前 multi 和 res 入栈，并分别置空置 00
            if (s[i] == '[') {
                strStack.emplace(str);
                numStack.emplace(num);
                str = "";
                num = 0;
            } else if (s[i] == ']') { // 当 c 为 ] 时，stack 出栈，拼接字符串 res = last_res + cur_multi * res
                string tmp;
                int curNum = numStack.top();
                numStack.pop();
                for (int j = 0; j < curNum; j++) tmp += str;
                string lastStr = strStack.top();
                strStack.pop();
                str = lastStr + tmp;
            } else if (s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i] - '0');
            else str += s[i];
        }

        return str;
    }
};








