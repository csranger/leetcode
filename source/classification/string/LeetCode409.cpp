//
// Created by zhaohailong on 2020/4/28.
//

/*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s)
    {
        int ret = 0;
        int charMap[128] = { 0 };
        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (charMap[i] % 2 == 0) ret += charMap[i];
            else ret += charMap[i] - 1;
        }
        if (ret != s.length()) {
            ret++;
        }
        return ret;
    }
};

int main()
{
    //1
    string str = "abccccdd";
    Solution s;
    cout << s.longestPalindrome(str) << endl;

    // 2
    string str2 = "bb";
    cout << s.longestPalindrome(str2) << endl;

    // 3
    string str3 = "ccc";
    cout << s.longestPalindrome(str3) << endl;
}