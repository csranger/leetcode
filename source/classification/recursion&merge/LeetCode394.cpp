//
// Created by zhaohailong on 2020/8/11.
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


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        return decode(s);
    }

    string decode(string s) {
        if (s.find_first_of(']') == string::npos) {
            return s;
        }

        int r = s.find_first_of(']');
        int l = s.rfind('[', r);
        int ll = 0;
        int num = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (s[i] - '0' > 9 || s[i] - '0' < 0) {
                ll = i;
                break;
            }
            num = num + (s[i] - '0') * pow(10, l - i - 1);
        }
        string temp = "";
        for (int i = 0; i < num; i++) {
            temp += s.substr(l + 1, r - l - 1);
        }
        string w;
        if (ll != 0) w = s.substr(0, ll + 1);

        string sw = w + temp + s.substr(r + 1);

        return decode(sw);
    }
};